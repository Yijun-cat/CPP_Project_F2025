#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Game 
{
public:
    Grid field;
    Castle castle;
    Tower* towers;
    Enemy enemy;

    Game(Grid &field, Castle &castle){
        this->field = field;
        this->castle = castle;
    }

    void init_game(){
        field.initGrid();
        field.grid[castle.row][castle.col] = 'C';
        field.displayGrid();
    }  

    void place_tower(Tower towers[5]){
        this->towers = towers;
        cout << "Place 5 towers in the grid (not in the top 2 rows and the castle cell)" << endl;
        int tower_num = 0;

        while ( tower_num < 5 ) {
            cout << "Enter row number of tower " << tower_num + 1 << endl;
            int row;
            cin >> row;
            if (row >= 2 && row <= 19) {
                bool legal_col = false;
                while (!legal_col) {
                    cout << "Enter column number of tower " << tower_num + 1 << endl;
                    int col;
                    cin >> col;
                    if (col >= 0 && col <= 19) {
                        Tower tower(row, col);
                        *(this->towers + tower_num) = tower;
                        field.grid[tower.row][tower.col] = 'T';
                        field.clearConsole();
                        field.displayGrid();
                        tower_num ++;
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
        this->field.displayGrid();
    }

    /*
    bool isCellEmpty(int r, int c){
        bool emptycell = true;
        if (field.grid[r][c] != '.'){
            emptycell = false;
        }

        return emptycell;
    }
    */

    void move_enemy(Enemy &e){
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