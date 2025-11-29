#ifndef TOWER_H_
#define TOWER_H_
#include <iostream>
#include "StaticObject.h"
#include "Enemy.h"

class Enemy;

class Tower : public StaticObject // Tower is a child class of StaticObject
{
private:
    int power = 1; // Default damage to an enemy
    int range = 2; // Default attack range
public:
    Tower(int r = 2, int c = 0); // Initialize with default values of row and column
    int getPower(); // return power
    int getRange(); // return range 
    void attack(Enemy &e); // Attack methods 
    void increasePower(); // Increase damage to an enemy
    void increaseRange(); // Increase attack range
};

#endif