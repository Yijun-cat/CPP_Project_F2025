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
    
    while ( wave < myGame.get_waveNumber() && !castle.isDestroyed() ){
        bool stopWave = false;
        int totalHealth = 0;
        Enemy enemies[myGame.get_enemiesPerWave()];

        while (!stopWave){
            for (int ei = 0; ei < myGame.get_enemiesPerWave(); ei++) {
                if ( !enemies[ei].spawned ) {
                    enemies[ei].row = 0;
                    enemies[ei].col = myAI.spawnEnemy(grid, towers);
                    enemies[ei].spawned = true;
                    for ( int ti = 0; ti < 5; ti++ ) {
                        towers[ti].attack(enemies[ei]);
                    }
                    if ( enemies[ei].health <= 0 ) {
                        grid.grid[enemies[ei].row][enemies[ei].col] = '.';
                    }
                }
                grid.displayGrid();

                for ( int ej = 0; ej < myGame.get_enemiesPerWave(); ej++ ) {
                    if ( enemies[ej].spawned && enemies[ej].health > 0 ){
                        myGame.moveEnemy(grid, enemies[ej]);
                        if (enemies[ej].row == 19){
                            castle.health -= 10;
                        } else {
                            for ( int tj = 0; tj < 5; tj++ ) {
                                towers[tj].attack(enemies[ej]);
                            }
                            if ( enemies[ej].health <= 0 ) {
                                grid.grid[enemies[ej].row][enemies[ej].col] = '.';
                            }
                        }
                        grid.displayGrid();       
                    }   
                }
            }

            // Sum health of enemies in current wave
            for ( int i = 0; i < myGame.get_enemiesPerWave(); i++ ){
                totalHealth += enemies[i].health;
            }

            // Check alive enemies
            if ( totalHealth <= 0 ){
                stopWave = true;   
            }

        wave++;
            //myGame.showResult(castle);
        }
    }

    return 0;
}
