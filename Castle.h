#ifndef CASTLE_H_
#define CASTLE_H_
#include <iostream>
#include "StaticObject.h"

class Castle : public StaticObject // Castle is a child class of StaticObject
{
private:
    int health = 100;
public:
    Castle (int r = 19, int c = 9); // Initialize with default values of row and column
    int getHealth(); // Return castle health
    void setHealth( int health ); // Set castle health 
    bool isDestroyed(); // Check if castle health is below or equal to zero
};

#endif