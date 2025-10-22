#ifndef TOWER_H_
#define TOWER_H_
#include <iostream>
#include "Enemy.h"
using namespace std;

class Tower 
{   
public:
    int row, col;

    Tower(int row = 2, int col = 0) {
        this->row = row;
        this->col = col;
    }

    void attack(Enemy &e) {
        if(abs(row-e.row) <=2 && abs(col-e.col) <=2) {
            e.health --;
        }
    }

    void towerUpgrade(){

    }

    void specialAttack(){
        
    }
    
};

#endif