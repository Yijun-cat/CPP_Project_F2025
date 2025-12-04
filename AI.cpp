#include <iostream>
#include "StaticObject.h"
#include "Tower.h"
#include "Enemy.h"
#include "Grid.h"
#include "AI.h"
using namespace std;

// Collect stats of enemy performance in each run
void AI::enemyPerformance( int colEnemySpawned, int rowReached, bool isCastleReached ) 
{
    colSpawned[colEnemySpawned]++; // record number of times a column where enemy is spawned
    colTotalDepth[colEnemySpawned] += rowReached; // record total depth an enemy reached in that column
    if ( isCastleReached ) 
    {
        colCastleReached[colEnemySpawned]++; // record number of times an enemy reached castle in column
    }
}

// Find a optimal column where an enemy can be spawned
int AI::spawnEnemy(Grid &field, int waveNum)
{
    bool findCol = false;
    int colChosen;
    while (!findCol)
    {
        //int search = 0;
        
        int col = rand() % 20;
        
        if ( waveNum == 1 ) // Randomly spawn enemy in empty cell in the first run
        {
            if ( field.isCellEmpty(0, col) ) 
            {
                colChosen = col;
                findCol = true;
            }
        }
        else // after first run start using adaptive spawning 
        {
            colChosen = strategicColumn(field);
            findCol = true;
        }
    }
    // Show enemy symbol in a cell
    field.grid[0][colChosen] = 'E';
    field.displayGrid();
    return colChosen;
}

// Strategic spawning in column where enemies have better performance
int AI::strategicColumn(Grid &field)
{
    double colScore[20];

    for ( int c = 0; c < 20; c++ ) 
    {
        if ( !field.isCellEmpty(0, c) ) {
            colScore[c] = -1.0; // cannot spawn in an occupied cell
        }
        if (colSpawned[c] == 0 ){ // No data collected in this column to evaluate performance
            colScore[c] = 0.5; // set a mid score
        }
        else
        {
            double survivalRate = (double) colCastleReached[c] / colSpawned[c];
            double avgDepth = (double) colTotalDepth[c] / colSpawned[c];
            colScore[c] = 0.7 * survivalRate + 0.3 * (avgDepth / 19.0);// weighted average of two values
        }
    }
    // Find max score among valid columns
    double maxScore = -1.0;
    for ( int c = 0; c < 20; c++ ) 
    {
        if ( colScore[c] > maxScore ) {
            maxScore = colScore[c];
        }
    }
    // Select column score >= 50% of max score
    int selectedCol[20];
    int count = 0;
    for ( int c = 0; c < 20; c++ )
    {
        if ( colScore[c] >= 0 && colScore[c] >= 0.5 * maxScore ) {
            selectedCol[count++] = c;
        }
    }
    //If no column score >= 0.5 * max score
    if ( count == 0) 
    {
        while( true )
        {
            int col = rand() % 20;
            if ( field.isCellEmpty(0, col) )
            {
                return col;
            } 
        }
    }
    // Randomly choose one of selected columns
    int idx = rand() % count;
    return selectedCol[idx]; 
}
    
// Change enemy health and speed to increase difficulty
void AI::adjustDifficulty(int waveScore, int enemiesPerWave, Enemy* enemies )
{
    // Increase enemy health if over 80% enemies do not survive in each wave
    if ( waveScore >= ( enemiesPerWave * 10 * 0.8) ) {
        for ( int i = 0; i < enemiesPerWave; i++ ){
            (enemies+i)->addHealth();
        }
    }
    // Increase enemy speed if no enemy survive in one wave
    if ( waveScore =  10 * enemiesPerWave ) {
        for ( int i = 0; i < enemiesPerWave; i++ ) {
            if ( i%4 == 0 ) {
                (enemies+i)->addSpeed();
                (enemies+i)->setHealth(4);
            }
        }
    }
}