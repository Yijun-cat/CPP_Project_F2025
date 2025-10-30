#include <iostream>
#include "Castle.h"
#include "Enemy.h"
#include "Tower.h"
#include "Grid.h"
#include "Game.h"
#include "AI.h"
using namespace std;

int main()
{
    // Initate game objects
    Grid grid;
    Castle castle;
    Tower towers[5];

    // Initate game management objects
    Game myGame;
    AI myAI;

    //Initiate the game, create the grid and place 5 towers
    myGame.init_game(grid, castle);
    myGame.place_tower(grid, towers);


    int wave_number = 0;

    return 0;
}
