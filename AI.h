#ifndef AI_H_
#define AI_H_
#include <iostream>
#include "Grid.h"
#include "Tower.h"
using namespace std;

class AI
{
private:
    int enemiesPerWave = 10;
public:
    Grid grid;
    Tower* towers;
    int total_enemies = 0;

    AI (Grid grid, Tower towers[]){
        this->grid = grid;
        this->towers = towers;
    }

    void spawnEnemies(int wave_number){
        int spawned = 0;
        srand(time(0));
        while (spawned < enemiesPerWave )
    }

    bool isCellNearTower(int c){
        for (int i = 0; i < sizeof(towers)/sizeof(towers[0]); i++){
            if(abs(towers[i].col - c) < 3){
                return true;
            }
        }
        return false;
    }

    void adjustDifficulty(int playerScore){

    }
};

#endif