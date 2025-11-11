#include "AI.h"
#include "Grid.h"
#include "Tower.h"
#include "Enemy.h"

int AI::spawnEnemy(Grid &field, Tower* towers){
    bool findCol = false;
    int col_chosen;
    while (!findCol){
        int search = 0;
        srand(time(0));
        int col = rand() % 20;
        while (search < 20){
            if (field.isCellEmpty(0, col) && !field.isCellNearTower(towers, col)){
                col_chosen = col;
                findCol = true;
                break;
            } else {
                search++;
            }
        }
        
        if ( field.isCellEmpty(0, col) ) {
            col_chosen = col;
            findCol = true;
        }
    }
    field.grid[0][col_chosen] = 'E';
    field.displayGrid();
    return col_chosen;
}
    
void AI::adjustDifficulty(int score, int waveNum, int enemiesPerWave, Enemy* enemies ){
    if ( score >= ((waveNum+1) * 10 * 0.8) ) {
        for ( int i = 0; i < enemiesPerWave; i++ ) {
            (enemies+i) -> addHealth( waveNum+1 );
        }
    }  
}