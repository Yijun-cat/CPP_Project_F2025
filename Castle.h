#ifndef CASTLE_H_
#define CASTLE_H_
#include <iostream>
#include "StaticObject.h"

class Castle : public StaticObject
{
public:
    int health;

    Castle (int r = 19, int c = 9) : StaticObject(r, c){
        this->health = 100;
    }

    int getHealth(){
        return this->health;
    }

    bool isDestroyed(){
        if (this->health <= 0){
            return true;
        }
        return false;
    }
};

#endif