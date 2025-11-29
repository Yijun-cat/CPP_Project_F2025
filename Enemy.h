#ifndef ENEMY_H_
#define ENEMY_H_
#include <iostream>
using namespace std;

class Enemy
{
private:
    // Properties of enemy
    int row, col; 
    int health, speed;
    bool spawned;
public:
    Enemy (int row = 0, int col = 0); // Constructor initialize class
    int getRow(); // Retrieve row number 
    void setRow( int row ); // Define row number 
    int getCol(); // Retrieve column number 
    void setCol( int col ); // Define column number
    int getSpeed(); // Retrieve speed value
    int getHealth(); // Retrieve enemy health
    void setHealth( int health ); // Define enemy health
    bool isSpawned(); // Check if an enemy is spawned
    void enemySpawned(); // Set spawned to true
    void moveDown(); // Move enemy down the grid
    void moveDiagonalLeft(); // Move diagnoally down left 
    void moveDiagonalRight(); // Move diagnoally down right
    void regenerate(); // reset enemy properties
    void addSpeed(); // increase enemy speed
    void addHealth(int hp); // increase enemy health
};

#endif