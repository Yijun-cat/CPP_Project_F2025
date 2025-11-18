#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "StaticObject.h"
#include "Tower.h"
#include "Grid.h"
using namespace std;

// Set up the battlefield
void Grid::initGrid(){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            this->grid[r][c] = '.';
        }
    }
}

// Refresh the battlefield for the next scene
void Grid::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Display the grid in the console
void Grid::displayGrid() {
    clearConsole();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}

bool Grid::isCellEmpty(int r, int c){
    if (grid[r][c] != '.'){
        return false;
    }
    return true;
}

bool Grid::isCellNearTower(Tower* towers, int c){
    for (int i = 0; i < 5; i++){
        if (abs(towers[i].getCol() - c) < 3){
            return true;
        }
    }
    return false;
}