#include <iostream>
#include "StaticObject.h"
#include "Enemy.h"
#include "Tower.h"

// Constructor initializes class
Tower::Tower(int r , int c) : StaticObject(r, c){}

// Retrieve power
int Tower::getPower(){
    return this->power;
}

// Retrieve range
int Tower::getRange(){
    return this->range;
}

// Attack an enemy within range
void Tower::attack(Enemy &e){
    int enemyHealth;
    enemyHealth = e.getHealth();
    // check damage to an enemy and attack range
    if (getPower() == 1 && getRange() == 2){
        // Calculate the distance between the location of an enemy and the tower
        if (abs(getRow()-e.getRow()) <=2 && abs(getCol()-e.getCol()) <=2){  
            enemyHealth--;         
            e.setHealth( enemyHealth );
        }
    } else if (getPower() == 2 && getRange() == 3){
        if (abs(getRow()-e.getRow()) <=3 && abs(getCol()-e.getCol()) <=3){
            enemyHealth-=2;
            e.setHealth( enemyHealth );
        }
    } else if (getPower() == 3 && getRange() == 4){
        if (abs(getRow()-e.getRow()) <=4 && abs(getCol()-e.getCol()) <=4){
            enemyHealth-=3;
            e.setHealth( enemyHealth );
        }
    }  
}

void Tower::increasePower() {
    // Increment damage to an enemy
    if ( this-> power < 3 ){
        this->power++;
    }    
}

void Tower::increaseRange() {
    // Increment attach range
    if ( this->range < 4 ) {
        this->range++;
    } 
}