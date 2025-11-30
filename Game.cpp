#include <iostream>
#include <limits>
#include "StaticObject.h"
#include "Castle.h"
#include "Tower.h"
#include "Enemy.h"
#include "Grid.h"
#include "Game.h"
using namespace std;

// Generate a grid and place the castle
void Game::init_game(Grid &field, Castle &castle){
    field.initGrid();
    field.grid[castle.getRow()][castle.getCol()] = 'C';
    field.displayGrid();
} 

// Retrieve total number of waves
int Game::getWaveNumber(){
    return this->totalWave;
}

// Retrieve number of enemies per wave
int Game::getEnemiesPerWave(){
    return this->enemiesPerWave;
}

// Helper function to detect invalid non-numeric input
int Game::readInt(const string& prompt)
{
    while (true) 
    {
        cout << prompt;
        int value;
        if ( cin >> value ) 
        {
            return value;
        }
        else
        {
            cout << "Invalid input. Please enter an integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Player choose cells where towers are placed
void Game::placeTower(Grid &field, Tower* towers){
    cout << endl;
    cout << "Place 5 towers in the grid (not in the top 2 rows and the castle cell)" << endl;
    int towerNum = 0;
    while ( towerNum < 5 ) {
        int rowChosen = readInt( "Enter row number of tower " + to_string(towerNum + 1) + " (3-20): ");
        int row = rowChosen-1;
        if (row >= 2 && row <= 19) { // First check if row number is valid
            while (true ) {
                int colChosen = readInt( "Enter column number of tower " + to_string(towerNum + 1) + " (1-20): ");
                int col = colChosen-1;
                if (col >= 0 && col <= 19 && field.isCellEmpty(row, col)){ // only valid cell positions are allowed
                    Tower tower(row, col);
                    *(towers + towerNum) = tower;
                    field.grid[tower.getRow()][tower.getCol()] = 'T'; // Place symbol T as tower in chosen cells
                    field.clearConsole();
                    field.displayGrid();
                    towerNum ++;
                    break;
                } else {
                    cout << "This column number is not allowed, try another one" << endl;
                    continue;
                }
            }
        } else {
            cout << "This row number is not allowed, try another one" << endl;
            continue;
        }
    }
    field.displayGrid();
}

// Enemy movement 
void Game::moveEnemy(Grid &field, Enemy &e){
    char* position = &field.grid[e.getRow()][e.getCol()];
    // Move 1 cell each turn when speed is 1
    if (e.getRow() < 19 && e.getSpeed()== 1){
        if (field.isCellEmpty(e.getRow() + 1, e.getCol())) {
            e.moveDown();
        } else if (e.getCol() > 0 && field.isCellEmpty(e.getRow() + 1, e.getCol() - 1)) {
            e.moveDiagonalLeft();
        } else if (e.getCol() < 19 && field.isCellEmpty(e.getRow() + 1, e.getCol() + 1)) {
            e.moveDiagonalRight();
        }
    }
    
    // Move two cells each turn when enemy speed is increased to 2
    if (e.getRow() < 18 && e.getSpeed() == 2){
        if ( field.isCellEmpty(e.getRow() + 2, e.getCol()) ) {
            e.moveDown();
        } else if ( e.getCol() > 1 && field.isCellEmpty(e.getRow() + 2, e.getCol() - 2) ) {
            e.moveDiagonalLeft();
        } else if ( e.getCol() < 18 && field.isCellEmpty(e.getRow() + 2, e.getCol() + 2) ) {
            e.moveDiagonalRight();
        }
    }

    // Update the grid after enemies move
    *position = '.';
    field.grid[e.getRow()][e.getCol()] = 'E';
    // Remove enemy after reaching castle row
    if (e.getRow() == 19){
        field.displayGrid();
        e.setHealth(0);
        field.grid[e.getRow()][e.getCol()] = '.';
    }  
}

// player pick one tower to upgrade
void Game::upgradeTower(Tower* towers) {
    while ( true ) {
        for ( int i = 0; i < 5; i++ ) {
        cout << "Tower " << i+1 
            << ", row: " << (towers+i)->getRow()+1
            << ", column: " << (towers+i)->getCol()+1 << endl;
        }
        cout << endl;
        cout << "Choose a tower number to upgrade, 1 to 5" << endl;
        int whichTower = readInt( "Choose a tower number to upgrade (1-5): ");
        if ( whichTower >=1 && whichTower <= 5 ) {
            int towerNum = whichTower-1;
            (towers+towerNum)->increasePower();
            (towers+towerNum)->increaseRange();
            break;
        } else {
            cout << "This tower number is not in towers, choose another one" << endl;
            continue;
        }
    } 
}

// Display game result
void Game::showResult(Castle castle, int score, int enemiesDestroyed){
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "GAME OVER" << endl;
    cout << "Player Score: " << score << endl;
    cout << "Enemies Destroyed: " << enemiesDestroyed << endl;
    
    if (castle.getHealth()> 0){
        cout << "Castle Health: " << castle.getHealth() << endl;
        cout << "Winner: Player" << endl;  
    } else {
        cout << "Castle Health: " << 0 << endl;
        cout << "Winner: AI" << endl;
    }   
}