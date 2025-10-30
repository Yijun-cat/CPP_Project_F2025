#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_
#include <iostream>

class StaticObject
{
private:
    int row;
    int col;
public:
    StaticObject(int r, int c){
        this->row = r;
        this->col = c;
    }

    int getRow(){
        return this->row;
    }

    int getCol(){
        return this->col;
    }
};

#endif