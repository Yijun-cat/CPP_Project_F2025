#ifndef AI_H_
#define AI_H_
#include <iostream>

using namespace std;

class AI
{
private:
    int enemiesPerWave = 10;
public:
    int total_enemies = 0;

    void spawnEnemy(Grid &field){
        int col = rand() % 20;
        if (field.isCellEmpty(0, col) && !field.isCellNearTower(0, col)){
            field.grid[0][col] = 'E';
        }
    }


    void adjustDifficulty(int playerScore){

    }
};

#endif