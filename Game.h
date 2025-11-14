#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Grid;
class Castle;
class Tower;
class Enemy;

class Game 
{
private:
    int totalWave = 5;
    int enemiesPerWave = 10;
public:
    void init_game(Grid &field, Castle &castle);
    int get_waveNumber();
    int get_enemiesPerWave();
    void place_tower(Grid &field, Tower* towers);
    void moveEnemy(Grid &field, Enemy &e);
    void upgradeTower(Tower* towers);
    void showResult(Castle castle, int score, int enemiesDestroyed);
};


void Game::init_game(Grid &field, Castle &castle){
    field.initGrid();
    field.grid[castle.getRow()][castle.getCol()] = 'C';
    field.displayGrid();
} 

int Game::get_waveNumber(){
    return this->totalWave;
}

int Game::get_enemiesPerWave(){
    return this->enemiesPerWave;
}

void Game::place_tower(Grid &field, Tower* towers){
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
    char* position = &field.grid[e.row][e.col];
    if (e.row < 19 && e.speed == 1){
        if (field.isCellEmpty(e.row + 1, e.col)) {
            e.moveDown();
        } else if (e.col > 0 && field.isCellEmpty(e.row + 1, e.col - 1)) {
            e.moveDiagonalLeft();
        } else if (e.col < 19 && field.isCellEmpty(e.row + 1, e.col + 1)) {
            e.moveDiagonalRight();
        }
    }
    
    if (e.row < 18 && e.speed == 2){
        if ( field.isCellEmpty(e.row + 2, e.col) ) {
            e.moveDown();
        } else if ( e.col > 1 && field.isCellEmpty(e.row + 2, e.col - 2) ) {
            e.moveDiagonalLeft();
        } else if ( e.col < 18 && field.isCellEmpty(e.row + 2, e.col + 2) ) {
            e.moveDiagonalRight();
        }
    }

    *position = '.';
    field.grid[e.row][e.col] = 'E';
    if (e.row == 19){
        field.displayGrid();
        e.health = 0;
        field.grid[e.row][e.col] = '.';
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
    
    if (castle.health > 0){
        cout << "Castle Health: " << castle.health << endl;
        cout << "Winner: Player" << endl;  
    } else {
        cout << "Castle Health: " << 0 << endl;
        cout << "Winner: AI" << endl;
    }   
}


#endif