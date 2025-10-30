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

    void spawnEnemies(int wave_number){
        int spawned = 0;
        srand(time(0));
        while (spawned < enemiesPerWave){
            
        }
    }

    bool isCellNearTower(Tower towers[], int c){
        for (int i = 0; i < sizeof(towers)/sizeof(towers[0]); i++){
            if (abs(towers[i].getCol() - c) < 3){
                return true;
            }
        }
        return false;
    }

    void adjustDifficulty(int playerScore){

    }
};

#endif