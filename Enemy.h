#ifndef ENEMY_H_
#define ENEMY_H_
#include <iostream>
using namespace std;

class Enemy
{
public:
    int row, col;
    int health, speed;

    Enemy(int row = 0, int col = 0){
        this->row = row;
        this->col = col;
        this->health = 3;
        this->speed = 1;
    }

    void move(){

    }
};

class fastEnemy : public Enemy 
{

};

class strongEnemy : public Enemy
{

};

#endif