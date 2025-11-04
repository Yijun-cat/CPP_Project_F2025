#ifndef AI_H_
#define AI_H_
#include <iostream>
using namespace std;

class AI
{
private:
    int enemiesPerWave = 10;
    int total_enemies = 50;
public:
    int spawnEnemy(Grid &field, Tower* towers){
        bool findCol = false;
        int col_chosen;
        while (!findCol){
            int search = 0;
            srand(time(0));
            int col = rand() % 20;
            while (search < 20){
                if (field.isCellEmpty(0, col) && !field.isCellNearTower(towers, col)){
                    col_chosen = col;
                    findCol = true;
                    break;
                } else {
                    search++;
                }
            }
            
            if ( field.isCellEmpty(0, col) ) {
                col_chosen = col;
                findCol = true;
            }
        }
        field.grid[0][col_chosen] = 'E';
        field.displayGrid();
        return col_chosen;
    }

    void adjustDifficulty(int playerScore){

    }
};

#endif