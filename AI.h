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
        int search = 0;
        while (search < 20){
            int col = rand() % 20;
            if (field.isCellEmpty(0, col) && !field.isCellNearTower(towers, col)){
                field.grid[0][col] = 'E';
                return col;
            }
            search++;
            field.grid[0][col] = 'E';
            if (search == 20){
                return col;
            }
        }
    }

    void adjustDifficulty(int playerScore){

    }
};

#endif