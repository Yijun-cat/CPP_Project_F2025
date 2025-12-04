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
    myGame.initiateGame(grid, castle);
    myGame.placeTower(grid, towers);

    // Variables for the game process
    int wave = 1;
    int score = 0;
    int enemiesDestroyed = 0;
    int enemyHealth = enemies[0].getHealth();
    int castleHealth = castle.getHealth();
    srand(time(0));
    
    // Run the game while castle health is > 0 and total wave <= 5
    while ( wave < myGame.getWaveNumber()+1 && !castle.isDestroyed() ){
        bool play = true;
        cout << endl;
        cout << "Wave " << wave << " starts in 3 seconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));

        // Game behavior in one wave
        while ( play ){
            int waveScore = 0;
            // Decide each enemy movement
            for (int ei = 0; ei < myGame.getEnemiesPerWave(); ei++) {
                // Spawn enemies
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
                grid.displayGrid(); // Update grid

                // Spawned enemies move
                for ( int ej = 0; ej < myGame.getEnemiesPerWave(); ej++ ) {
                    if ( enemies[ej].isSpawned() && enemies[ej].getHealth() > 0 ){
                        myGame.moveEnemy(grid, enemies[ej]);
                        if (enemies[ej].getRow() == 19){ // Deal damage to castle when reach castle row
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
                    
                        grid.displayGrid(); // Update the grid after enemy move
                    }
                    if ( castle.isDestroyed() ){ // Stop enemies move if castle is destroyed
                        break;
                    }    
                }
            }  
           
            play = false;
            // Check wave ends condition
            if ( !castle.isDestroyed() ) {
                for ( int i = 0; i < myGame.getEnemiesPerWave(); i++) {
                    if ( enemies[i].getHealth() > 0 ) { // Wave continues if there is an enemy alive
                        play = true;
                        break;
                    }
                }
            }   
              
            // Update game results and change game difficulty if current wave ends
            if ( !play ) {
                for ( int i = 0; i < myGame.getEnemiesPerWave(); i++ ) {
                    if ( enemies[i].getRow() != 19 && enemies[i].getHealth() <= 0 ) {
                        waveScore += 10;
                        score += 10;
                        enemiesDestroyed++;
                    }
                    myAI.enemyPerformance( enemies[i].getCol(), enemies[i].getRow(), enemies[i].isCastleReached() );
                    enemies[i].regenerate(enemyHealth); // reset enemy parameters to spawn in next wave
                }
                
                if ( wave < 5 ) {
                    myAI.adjustDifficulty( waveScore, myGame.getEnemiesPerWave(), enemies ); // Change enemy properies to increase difficulty
                    enemyHealth = enemies[0].getHealth();
                    cout << endl;
                    cout << "Enemy health in next wave: " << enemies[0].getHealth() << endl; // show difficulty in next wave
                    // tower upgrade
                    if ( waveScore >= (myGame.getEnemiesPerWave() * 10 * 0.8) && wave < myGame.getWaveNumber() ) {
                        cout << endl;
                        myGame.upgradeTower(towers);
                    }    
                } 
                wave += 1; // increment wave number when current wave ends       
            }
        }
    }

    // Display game result when game ends
    myGame.showResult(castle, score, enemiesDestroyed);

    return 0;
}
