#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_
#include <iostream>

class StaticObject // Object once placed cannot move 
{
private:
    // Properties of static object
    int row;
    int col;
public:
    StaticObject(int r, int c); // Initialize row and column
    int getRow(); // Retrieve row number of the object
    int getCol(); // Retrieve column number of the object
};

#endif