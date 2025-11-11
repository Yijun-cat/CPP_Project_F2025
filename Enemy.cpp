#include "Enemy.h"

Enemy::Enemy (int row = 0, int col = 0){
    this->row = row;
    this->col = col;
    this->health = 3;
    this->speed = 1;
    this->spawned = false;
}

void Enemy::moveDown(){
    if (this->speed = 1){
        this->row ++;
    } else {
        this->row += 2;
    }
}

void Enemy::moveDiagonalLeft(){
    if (this->speed = 1){
        this->row ++;
        this->col --;
    } else {
        this->row += 2;
        this->col -= 2;
    }
}

void Enemy::moveDiagonalRight(){
    if (this->speed = 1){
        this->row ++;
        this->col ++;
    } else {
        this->row += 2;
        this->col += 2;
    }
}

void Enemy::regenerate() {
    this->spawned = false;
    this->health = 3;
}

void Enemy::addSpeed(){
    this->speed++;
}

void Enemy::addHealth(int hp){
    this->health += hp;
}