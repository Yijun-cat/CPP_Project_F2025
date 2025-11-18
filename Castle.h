#ifndef CASTLE_H_
#define CASTLE_H_
#include <iostream>
#include "StaticObject.h"

class Castle : public StaticObject
{
public:
    int health;
    Castle (int r = 19, int c = 9);
    int getHealth();
    bool isDestroyed();
};

/*
Castle::Castle (int r = 19, int c = 9) : StaticObject(r, c){
    this->health = 100;
}

int Castle::getHealth(){
    return this->health;
}

bool Castle::isDestroyed(){
    if (this->health <= 0){
        return true;
    }
    return false;
}
*/


#endif