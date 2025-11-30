#include <iostream>
#include "Enemy.h"
using namespace std;

// Constructor initalizes class with some default values
Enemy::Enemy (int row, int col){
    this->row = row;
    this->col = col;
    this->health = 3;
    this->speed = 1;
    this->spawned = false;
}

int Enemy::getRow() {
    return this->row;
}

void Enemy::setRow( int row ) {
    this->row = row;
}

int Enemy::getCol() {
    return this->col;
}

void Enemy::setCol( int col ) {
    this->col = col;
}

int Enemy::getSpeed(){
    return this->speed;
}

int Enemy::getHealth(){
    return this->health;
}

void Enemy::setHealth(int health){
    this->health = health;
}

// Check if an enemy is spawned
bool Enemy::isSpawned() {
    return this->spawned;
}

// Set spawned to true
void Enemy::enemySpawned() {
    this->spawned = true;
}

// Move enemy downward
void Enemy::moveDown(){
    // Check enemy speed to set steps
    if (this->speed = 1){
        this->row ++;
    } else {
        this->row += 2;
    }
}

// Move enemy diagonally down left
void Enemy::moveDiagonalLeft(){
    // Check enemy speed to determine steps
    if (this->speed = 1){
        this->row ++;
        this->col --;
    } else {
        this->row += 2;
        this->col -= 2;
    }
}

// Move enemy diagonally down right
void Enemy::moveDiagonalRight(){
    if (this->speed = 1){
        this->row ++;
        this->col ++;
    } else {
        this->row += 2;
        this->col += 2;
    }
}

// Check whether an enmey reached castle row
bool Enemy::isCastleReached() 
{
    if ( this->row == 19 )
    {
        return true;
    }
    return false;
}

// Reset enemy to spawn in next wave
void Enemy::regenerate(int hp) {
    this->spawned = false;
    this->health = hp;
}

// Increas enemy speed to 2 as maximum speed
void Enemy::addSpeed(){
    this->speed = 2;
}

// Increment enemy health
void Enemy::addHealth(){
    this->health++;
}