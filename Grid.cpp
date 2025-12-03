#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "StaticObject.h"
#include "Tower.h"
#include "Grid.h"
using namespace std;

// Generate a grid
void Grid::initGrid(){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            this->grid[r][c] = '.';
        }
    }
}

// Clean current display in console
void Grid::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Dynamically refresh the display of grid in console
void Grid::displayGrid() {
    clearConsole();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    // Interval between each display
    this_thread::sleep_for(chrono::milliseconds(100));
}

// Check if a cell is empty
bool Grid::isCellEmpty(int r, int c){
    if (grid[r][c] != '.'){
        return false;
    }
    return true;
}