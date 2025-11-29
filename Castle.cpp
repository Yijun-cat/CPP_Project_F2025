#include <iostream>
#include "StaticObject.h"
#include "Castle.h"

// Constructor initialzes class 
Castle::Castle (int r, int c) : StaticObject(r, c){
    this->health = 100;
}

// Retrieve castle health
int Castle::getHealth(){
    return this->health;
}

// Define castle health
void Castle::setHealth( int health ) {
    this->health = health;
}

// Check castle health
bool Castle::isDestroyed(){
    if (this->health <= 0){
        return true;
    }
    return false;
}