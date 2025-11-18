#ifndef TOWER_H_
#define TOWER_H_
#include <iostream>
#include "StaticObject.h"
#include "Enemy.h"

class Enemy;

class Tower : public StaticObject
{
private:
    int power = 1;
    int range = 2;
public:
    Tower(int r = 2, int c = 0);
    int getPower();
    int getRange();
    void attack(Enemy &e);
    void increasePower();
    void increaseRange();
};

/*
Tower::Tower(int r = 2, int c = 0) : StaticObject(r, c){}

int Tower::getPower(){
    return this->power;
}

int Tower::getRange(){
    return this->range;
}

void Tower::attack(Enemy &e){
    if (getPower() == 1 && getRange() == 2){
        if (abs(getRow()-e.row) <=2 && abs(getCol()-e.col) <=2){
            e.health--;
        }
    } else if (getPower() == 2 && getRange() == 3){
        if (abs(getRow()-e.row) <=3 && abs(getCol()-e.col) <=3){
            e.health -= 2;
        }
    } else if (getPower() == 3 && getRange() == 4){
        if (abs(getRow()-e.row) <=4 && abs(getCol()-e.col) <=4){
            e.health -= 3;
        }
    }  
}

void Tower::increasePower() {
    this->power++;
}

void Tower::increaseRange() {
    this->range++;
}
*/

#endif