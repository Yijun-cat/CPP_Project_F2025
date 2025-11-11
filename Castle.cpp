#include "Castle.h"

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