#ifndef ENEMY_H_
#define ENEMY_H_
#include <iostream>
using namespace std;

class Enemy
{
public:
    int row, col;
    int health, speed;
    bool is_spawned;

    Enemy (int row = 0, int col = 0){
        this->row = row;
        this->col = col;
        this->health = 3;
        this->speed = 1;
        this->is_spawned = false;
    }

    void beFast(){
        this->speed = 2;
    }

    void beStrong(){
        this->health = 4;
    }
};

#endif