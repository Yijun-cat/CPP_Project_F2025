#ifndef CASTLE_H_
#define CASTLE_H_
#include <iostream>
#include "StaticObject.h"

class Castle : public StaticObject
{
private:
    int health;
public:
    Castle (int r = 19, int c = 9) : StaticObject(r, c){
        this->health = 100;
    }
};

#endif