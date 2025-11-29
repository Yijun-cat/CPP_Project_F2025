#include <iostream>
#include "StaticObject.h"
#include "Castle.h"
#include "Tower.h"
#include "Enemy.h"
#include "Grid.h"
#include "Game.h"
using namespace std;


void Game::init_game(Grid &field, Castle &castle){
    field.initGrid();
    field.grid[castle.getRow()][castle.getCol()] = 'C';
    field.displayGrid();
} 

int Game::getWaveNumber(){
    return this->totalWave;
}

int Game::getEnemiesPerWave(){
    return this->enemiesPerWave;
}

void Game::placeTower(Grid &field, Tower* towers){
    cout << endl;
    cout << "Place 5 towers in the grid (not in the top 2 rows and the castle cell)" << endl;
    int towerNum = 0;
    while ( towerNum < 5 ) {
        cout << "Enter row number of tower " << towerNum + 1 << endl;
        int rowChosen;
        cin >> rowChosen;
        int row = rowChosen-1;
        if (row >= 2 && row <= 19) {
            while (true ) {
                cout << "Enter column number of tower " << towerNum + 1 << endl;
                int colChosen;
                cin >> colChosen;
                int col = colChosen-1;
                if (col >= 0 && col <= 19 && field.isCellEmpty(row, col)){
                    Tower tower(row, col);
                    *(towers + towerNum) = tower;
                    field.grid[tower.getRow()][tower.getCol()] = 'T';
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

void Game::moveEnemy(Grid &field, Enemy &e){
    char* position = &field.grid[e.getRow()][e.getCol()];
    if (e.getRow() < 19 && e.getSpeed()== 1){
        if (field.isCellEmpty(e.getRow() + 1, e.getCol())) {
            e.moveDown();
        } else if (e.getCol() > 0 && field.isCellEmpty(e.getRow() + 1, e.getCol() - 1)) {
            e.moveDiagonalLeft();
        } else if (e.getCol() < 19 && field.isCellEmpty(e.getRow() + 1, e.getCol() + 1)) {
            e.moveDiagonalRight();
        }
    }
    
    if (e.getRow() < 18 && e.getSpeed() == 2){
        if ( field.isCellEmpty(e.getRow() + 2, e.getCol()) ) {
            e.moveDown();
        } else if ( e.getCol() > 1 && field.isCellEmpty(e.getRow() + 2, e.getCol() - 2) ) {
            e.moveDiagonalLeft();
        } else if ( e.getCol() < 18 && field.isCellEmpty(e.getRow() + 2, e.getCol() + 2) ) {
            e.moveDiagonalRight();
        }
    }

    *position = '.';
    field.grid[e.getRow()][e.getCol()] = 'E';
    if (e.getRow() == 19){
        field.displayGrid();
        e.setHealth(0);
        field.grid[e.getRow()][e.getCol()] = '.';
    }  
}

// player chooses which tower to upgrade
void Game::upgradeTower(Tower* towers) {
    int whichTower;
    
    while ( true ) {
        for ( int i = 0; i < 5; i++ ) {
        cout << "Tower " << i+1 
            << ", row: " << (towers+i)->getRow()+1
            << ", column: " << (towers+i)->getCol()+1 << endl;
        }
        cout << "Choose a tower number to upgrade, 1 to 5" << endl;
        cin >> whichTower;
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