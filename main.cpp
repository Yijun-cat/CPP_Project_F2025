#include <iostream>
#include "Castle.h"
#include "Enemy.h"
#include "Tower.h"
#include "Grid.h"
#include "Game.h"
#include "AI.h"
using namespace std;

int main()
{
    // Initate game objects
    Grid grid;
    Castle castle;
    Tower towers[5];

    // Initate game management objects
    Game myGame;
    AI myAI;

    //Initiate the game, create the grid and place 5 towers
    myGame.init_game(grid, castle);
    myGame.place_tower(grid, towers);

    int wave = 0;
    int spawned = 0;

    while (wave < 5){
        Enemy enemies[10] = {};

        for (int i = 0; i < 10; i++){
            if (enemies[i].is_spawned){
                myGame.move_enemy(grid, enemies[i]);
            }
        }
        grid.displayGrid();

        if (spawned < 10){
            enemies[spawned].row = 0;
            enemies[spawned].col = myAI.spawnEnemy(grid, towers);
        }
    }

    return 0;
}
