#ifndef AI_H_
#define AI_H_
#include <iostream>
#include "StaticObject.h"
#include "Tower.h"
#include "Enemy.h"
#include "Grid.h"
using namespace std;

class Grid;
class Tower;
class Enemy;

class AI
{
private:
    // Properties of class AI
    int colSpawned[20] = {0}; // stats of column where enemy is spwaned
    int colCastleReached[20] = {0}; // stats of column where enemy reach castle row
    int colTotalDepth[20] = {0}; // max row reached in each column
public:
    void enemyPerformance( int colEnemySpawned, int rowReached, bool isCastleReached ); // Collect stats of enemy performance in each run
    int spawnEnemy(Grid &field, int waveNum); // Return column number of a spwaned enemy
    int strategicColumn( Grid &field); // adaptive spawning using collected stats
    void adjustDifficulty(int score, int enemiesPerWave, Enemy* enemies ); // Change enemy health and speed to increase difficulty
};

#endif