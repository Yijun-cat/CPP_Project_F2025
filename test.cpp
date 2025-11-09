#include <iostream>
#include "Enemy.h"
using namespace std;

void show_health(Enemy* enemies){
        for (int i = 0; i < 10; i++){
           cout << (enemies+i)->health + 1 << endl;
        }
    }

int main() 
{
    Enemy enemies[10];
    //Enemy* ptr = enemies;

    show_health( enemies );

    return 0;
}
