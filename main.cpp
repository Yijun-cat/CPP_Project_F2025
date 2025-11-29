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
    Enemy enemies[myGame.getEnemiesPerWave()];

    //Initiate the game, create the grid and place 5 towers
    myGame.init_game(grid, castle);
    myGame.placeTower(grid, towers);

    int wave = 1;
    int score = 0;
    int enemiesDestroyed = 0;
    int castleHealth = castle.getHealth();
    srand(time(0));
    
    // Run the game while castle health is > 0 and 
    while ( wave <= myGame.getWaveNumber() && !castle.isDestroyed() ){
        bool play = true;
        cout << endl;
        cout << "Wave " << wave << " starts in 3 seconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));

        while ( play ){
            int waveScore = 0;

            for (int ei = 0; ei < myGame.getEnemiesPerWave(); ei++) {
                if ( !enemies[ei].isSpawned() ) {
                    enemies[ei].setRow( 0 );
                    enemies[ei].setCol( myAI.spawnEnemy(grid, wave) );
                    enemies[ei].enemySpawned();
                    for ( int ti = 0; ti < 5; ti++ ) {
                        towers[ti].attack(enemies[ei]);
                    }
                    if ( enemies[ei].getHealth() <= 0 ) {
                        grid.grid[enemies[ei].getRow()][enemies[ei].getCol()] = '.';
                    }
                }
                grid.displayGrid();

                for ( int ej = 0; ej < myGame.getEnemiesPerWave(); ej++ ) {
                    if ( enemies[ej].isSpawned() && enemies[ej].getHealth() > 0 ){
                        myGame.moveEnemy(grid, enemies[ej]);
                        if (enemies[ej].getRow() == 19){
                            castleHealth -= 10;
                            castle.setHealth ( castleHealth);
                        } else {
                            for ( int tj = 0; tj < 5; tj++ ) {
                                towers[tj].attack(enemies[ej]);
                            }
                            if ( enemies[ej].getHealth() <= 0 ) {
                                grid.grid[enemies[ej].getRow()][enemies[ej].getCol()] = '.';
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
            for ( int i = 0; i < myGame.getEnemiesPerWave(); i++) {
                if ( enemies[i].getHealth() > 0 ) {
                    play = true;
                    break;
                }
            }

            if ( !play ) {
                for ( int i = 0; i < myGame.getEnemiesPerWave(); i++ ) {
                    if ( enemies[i].getRow() != 19 && enemies[i].getHealth() <= 0 ) {
                        waveScore += 10;
                        score += 10;
                        enemiesDestroyed++;
                    }
                    enemies[i].regenerate();
                }

                myAI.adjustDifficulty( score, wave, myGame.getEnemiesPerWave(), enemies );
                if ( wave < 5 ) {
                    cout << endl;
                    cout << "Enemy health in next wave: " << enemies[0].getHealth() << endl;
                }
                
                // tower upgrade
                if ( waveScore >= (myGame.getEnemiesPerWave() * 10 * 0.8) && wave < myGame.getWaveNumber() ) {
                    myGame.upgradeTower(towers);
                }

                wave += 1;
            }
        }
    }

    myGame.showResult(castle, score, enemiesDestroyed);

    return 0;
}
