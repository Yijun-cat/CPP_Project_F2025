#include <iostream>
#include "StaticObject.h"

StaticObject::StaticObject(int r, int c){
    this->row = r;
    this->col = c;
}

int StaticObject::getRow(){
    return this->row;
}

int StaticObject::getCol(){
    return this->col;
}