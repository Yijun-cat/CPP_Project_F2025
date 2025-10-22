#ifndef CASTLE_H_
#define CASTLE_H_
#include <iostream>
using namespace std;

class Castle 
{
public:
    int row, col;
    int health;

    Castle(int row = 19, int col = 9) {
        this->row = row;
        this->col = col;
        this->health = 100;
    }
};

#endif