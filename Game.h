#ifndef GAME_H_
#define GAME_H_
#include <iostream>
using namespace std;

class Game 
{
private:
    // Properties of the game
    int totalWave = 5;
    int enemiesPerWave = 10;
public:
    void initiateGame(Grid &field, Castle &castle); // Generate a grid and place the castle
    int getWaveNumber(); // Retrieve total number of waves
    int getEnemiesPerWave(); // Retrieve number of enemies per wave
    int readInt(const string& prompt); // only read intger input and detect invalid non-numeric input
    void placeTower(Grid &field, Tower* towers); // Player choose where tower are placed
    void moveEnemy(Grid &field, Enemy &e); // enemy movement
    void upgradeTower(Tower* towers); // Upgrade tower
    void showResult(Castle castle, int score, int enemiesDestroyed); // show game result
};

#endif