#include <iostream>
#include "StaticObject.h"
#include "Enemy.h"
#include "Tower.h"

Tower::Tower(int r , int c) : StaticObject(r, c){}

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