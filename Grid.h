#ifndef GRID_H_
#define GRID_H_
#include <iostream>
#include <cstdlib>
using namespace std;

class Grid 
{
private:
    static const int rows = 20;
    static const int cols = 20;
public:
    char grid[rows][cols];

    // Set up the battlefield
    void initGrid(){
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                this->grid[r][c] = '.';
            }
        }
    }

    // Refresh the battlefield for the next scene
    void clearConsole() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // Display the grid in the console
    void displayGrid() {
        clearConsole();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid[r][c] << " ";
            }
            cout << endl;
        }
    }

    bool isCellEmpty(int r, int c){
        if (grid[r][c] != '.'){
            return false;
        }
        return true;
    }

    bool isCellNearTower(Tower* towers, int c){
        for (int i = 0; i < 5; i++){
            if (abs(towers[i].getCol() - c) < 3){
                return true;
            }
        }
        return false;
    }
};

#endif