#ifndef TOWER_H_
#define TOWER_H_
#include <iostream>
#include "StaticObject.h"

class Tower : public StaticObject
{   
public:
    Tower(int r = 2, int c = 0) : StaticObject(r, c){}

    void attack(Enemy &e){
        if (abs(getRow()-e.row) <=2 && abs(getCol()-e.col) <=2){
            e.health --;
        }
    }

    void towerUpgrade(){

    }

    void specialAttack(){
        
    } 
};

#endif