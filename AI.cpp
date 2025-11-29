#include <iostream>
#include "StaticObject.h"
#include "Tower.h"
#include "Enemy.h"
#include "Grid.h"
#include "AI.h"
using namespace std;

void AI::enemyPerformance( int colEnemySpawned, int rowReached, bool isCastleReached ) {
    colSpawned[colEnemySpawned]++;
    colTotalDepth[colEnemySpawned] += rowReached;
    if ( isCastleReached ) 
    {
        colCastleReached[colEnemySpawned]++;
    }
}

// Find a optimal column where an enemy can be spawned
int AI::spawnEnemy(Grid &field, int waveNum){
    bool findCol = false;
    int colChosen;
    while (!findCol)
    {
        //int search = 0;
        
        int col = rand() % 20;
        
        if ( waveNum == 1 )
        {
            if ( field.isCellEmpty(0, col) ) 
            {
                colChosen = col;
                findCol = true;
            }
        }
        else
        {
            colChosen = strategicColumn(field);
            findCol = true;
        }
    }

    field.grid[0][colChosen] = 'E';
    field.displayGrid();
    return colChosen;
}

int AI::strategicColumn(Grid &field)
{
    double colScore[20];

    for ( int c = 0; c < 20; c++ ) 
    {
        if ( !field.isCellEmpty(0, c) )
        {
            colScore[c] = -1.0; // cannot spawn in an occupied cell
        }

        if (colSpawned[c] == 0 ) // No data collected in this column to evaluate performance
        {
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
    double maxColScore = -1.0;
    for ( int c = 0; c < 20; c++ ) 
    {
        if ( colScore[c] > maxColScore )
        {
            maxColScore = colScore[c];
        }
    }

    /*
    // Collect all “good enough” columns (within 80% of max score)
    int candidates[20];
    int count = 0;
    for (int c = 0; c < 20; ++c) {
        if (scores[c] >= 0 && scores[c] >= 0.8 * maxScore) {
            candidates[count++] = c;
        }
    }

    // Fallback: if something went wrong, pick any empty column
    if (count == 0) {
        while (true) {
            int col = rand() % 20;
            if (field.isCellEmpty(0, col)) return col;
        }
    }

    // Randomly choose one of the best candidates
    int idx = rand() % count;
    return candidates[idx];
    */
}
    
void AI::adjustDifficulty(int score, int waveNum, int enemiesPerWave, Enemy* enemies ){
    // increase enemy health if over 80% enemies do not survive in each wave
    if ( score >= ( waveNum * 10 * enemiesPerWave * 0.8 ) ) {
        for ( int i = 0; i < enemiesPerWave; i++ ) {
            (enemies+i)->regenerate();
            (enemies+i)->addHealth( waveNum );
        }
    }
    // Increase enemy speed if no enemy survive in continuous wave
    if ( score = ( waveNum * 10 * enemiesPerWave) ) {
        for ( int i = 0; i < enemiesPerWave; i++ ) {
            if ( i%2 == 0 ) {
                (enemies+i)->addSpeed();
            }
        }
    }
}