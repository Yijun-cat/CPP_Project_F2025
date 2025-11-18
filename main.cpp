#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "StaticObject.h"
#include "Castle.h"
#include "Tower.h"
#include "Enemy.h"
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
    Enemy enemies[myGame.get_enemiesPerWave()];

    //Initiate the game, create the grid and place 5 towers
    myGame.init_game(grid, castle);
    myGame.place_tower(grid, towers);

    int wave = 0;
    int score = 0;
    int enemiesDestroyed = 0;
    
    while ( wave < myGame.get_waveNumber() && !castle.isDestroyed() ){
        bool play = true;
        cout << endl;
        cout << "Wave " << wave+1 << " starts in 3 seconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));

        while ( play ){
            int waveScore = 0;

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
                        if ( castle.isDestroyed() ) {
                            break;
                        }       
                    }   
                }
            }

            play = false;
            for ( int i = 0; i < myGame.get_enemiesPerWave(); i++) {
                if ( enemies[i].health > 0 ) {
                    play = true;
                    break;
                }
            }

            if ( !play ) {
                for ( int i = 0; i < myGame.get_enemiesPerWave(); i++ ) {
                    if ( enemies[i].row != 19 && enemies[i].health <= 0 ) {
                        waveScore += 10;
                        score += 10;
                        enemiesDestroyed++;
                    }
                    enemies[i].regenerate();
                }

                myAI.adjustDifficulty( score, wave, myGame.get_enemiesPerWave(), enemies );
                for ( int i = 0; i < 10; i++) {
                    cout << enemies[i].health << endl;
                }

                // tower upgrade
                if ( waveScore >= (myGame.get_enemiesPerWave() * 10 * 0.8) && wave < myGame.get_waveNumber()-1 ) {
                    myGame.upgradeTower(towers);
                }

                wave += 1;
            }
        }
    }

    myGame.showResult(castle, score, enemiesDestroyed);

    return 0;
}
