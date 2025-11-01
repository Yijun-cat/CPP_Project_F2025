#ifndef TOWER_H_
#define TOWER_H_
#include <iostream>
#include "StaticObject.h"

class Tower : public StaticObject
{
private:
    int power = 1;
    int range = 2;
public:
    Tower(int r = 2, int c = 0) : StaticObject(r, c){}

    int getPower(){
        return this->power;
    }

    int getRange(){
        return this->range;
    }

    void setPower(int power){
        this->power = power;
    }

    void setRange(int range){
        this->range = range;
    }

    void attack(Enemy &e){
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

    void towerUpgrade(int playerScore){
        if (playerScore >= 200 && playerScore < 300){
            setPower(2);
            setRange(3);
        } else if (playerScore >= 300){
            setPower(3);
            setRange(4);
        } 
    }

    void specialAttack(){
        
    } 
};

#endif