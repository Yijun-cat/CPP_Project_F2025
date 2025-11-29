#ifndef GRID_H_
#define GRID_H_
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Tower.h"
using namespace std;

class Grid 
{
private:
    static const int rows = 20; // Default number of rows of a grid
    static const int cols = 20; // Default number of columns of gird
public:
    char grid[rows][cols]; // Grid is represented as a nested array
    void initGrid(); // Initialize a grid
    void clearConsole(); // Refresh the display of a grid to make it dynamic 
    void displayGrid(); // Show current grid
    bool isCellEmpty(int r, int c); // Check if a cell in the grid is empty
    //bool isCellNearTower(Tower* towers, int c); // Check if the colum number of a cell 
                                                // is close to the column number of any tower
};

#endif