#include <iostream>
#include "Castle.h"
//#include "Enemy.h"
#include "Tower.h"
//#include "AI.h"
#include "Grid.h"
#include "Game.h"
using namespace std;

int main()
{
    // Initiate the battle field
    Grid grid;
    Castle castle;
    Tower towers[5];

    Game game(grid, castle);

    game.init_game();
    game.place_tower(towers);

    return 0;
}
