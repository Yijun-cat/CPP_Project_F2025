#include <iostream>
#include "StaticObject.h"

// Initialize class
StaticObject::StaticObject(int r, int c){
    this->row = r;
    this->col = c;
}

// Retrieve row number
int StaticObject::getRow(){
    return this->row;
}

// Retrieve column number
int StaticObject::getCol(){
    return this->col;
}