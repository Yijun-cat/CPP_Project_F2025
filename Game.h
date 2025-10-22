#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Game 
{
public:
    Grid battlefield;
    Castle castle;
    Tower* towers;

    Game(Grid grid, Castle castle){
        this->battlefield = battlefield;
        this->castle = castle;
    }

    void init_game(){
        battlefield.initGrid();
        battlefield.grid[castle.row][castle.col] = 'C';
        battlefield.displayGrid();
    }  

    void place_tower(Tower towers[5]){
        this->towers = towers;
        cout << "Place 5 towers in the grid (not in the top 2 rows and castle cell)" << endl;
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
                        battlefield.grid[tower.row][tower.col] = 'T';
                        battlefield.clearConsole();
                        battlefield.displayGrid();
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
        this->battlefield.displayGrid();
    }
};

#endif