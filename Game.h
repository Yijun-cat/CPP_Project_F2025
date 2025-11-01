#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Game 
{
private:
    int waveNumber = 5;
    int enemiesPerWave = 10;
public:
    void init_game(Grid &field, Castle &castle){
        field.initGrid();
        field.grid[castle.getRow()][castle.getCol()] = 'C';
        field.displayGrid();
    }  

    void place_tower(Grid &field, Tower* towers){
        cout << "Place 5 towers in the grid (not in the top 2 rows and the castle cell)" << endl;
        int towerNum = 0;

        while ( towerNum < 5 ) {
            cout << "Enter row number of tower " << towerNum + 1 << endl;
            int row;
            cin >> row;
            if (row >= 2 && row <= 19) {
                bool legal_col = false;
                while (!legal_col) {
                    cout << "Enter column number of tower " << towerNum + 1 << endl;
                    int col;
                    cin >> col;
                    if (col >= 0 && col <= 19 && field.isCellEmpty(row, col)){
                        Tower tower(row, col);
                        *(towers + towerNum) = tower;
                        field.grid[tower.getRow()][tower.getCol()] = 'T';
                        field.clearConsole();
                        field.displayGrid();
                        towerNum ++;
                        legal_col = true;
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

    void move_enemy(Grid &field, Enemy &e){
        char* position = &field.grid[e.row][e.col];
        if (e.row < 19){
            if (field.isCellEmpty(e.row + 1, e.col)){
                e.row++;
            } else if (e.col > 0 && field.isCellEmpty(e.row + 1, e.col - 1)){
                e.row++;
                e.col--;
            } else if (e.col < 19 && field.isCellEmpty(e.row + 1, e.col + 1)){
                e.row++;
                e.col++;
            }
            *position = '.';
            field.grid[e.row][e.col] = 'E';
        }
    }


};

#endif