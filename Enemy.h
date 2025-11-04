#ifndef ENEMY_H_
#define ENEMY_H_
#include <iostream>
using namespace std;

class Enemy
{
public:
    int row, col;
    int health, speed;
    bool spawned;


    Enemy (int row = 0, int col = 0){
        this->row = row;
        this->col = col;
        this->health = 3;
        this->speed = 1;
        this->spawned = false;
    }

    void moveDown(){
        if (this->speed = 1){
            this->row ++;
        } else {
            this->row += 2;
        }
    }

    void moveDiagonalLeft(){
        if (this->speed = 1){
            this->row ++;
            this->col --;
        } else {
            this->row += 2;
            this->col -= 2;
        }
    }

    void moveDiagonalRight(){
        if (this->speed = 1){
            this->row ++;
            this->col ++;
        } else {
            this->row += 2;
            this->col += 2;
        }
    }

    bool isDead(){
        if (this->health <= 0){
            return true;
        }
        return false;
    }

    void addSpeed(){
        this->speed++;
    }

    void addHealth(){
        this->health++;
    }
};

#endif