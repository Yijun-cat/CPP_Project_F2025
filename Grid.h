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

    void displayGrid() {
        clearConsole();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid[r][c] << " ";
            }
            cout << endl;
        }
    }
    void update(){

    }

};

#endif