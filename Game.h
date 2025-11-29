#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Game 
{
private:
    int totalWave = 5;
    int enemiesPerWave = 10;
public:
    void init_game(Grid &field, Castle &castle);
    int getWaveNumber();
    int getEnemiesPerWave();
    void placeTower(Grid &field, Tower* towers);
    void moveEnemy(Grid &field, Enemy &e);
    void upgradeTower(Tower* towers);
    void showResult(Castle castle, int score, int enemiesDestroyed);
};

#endif