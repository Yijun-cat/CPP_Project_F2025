#include <iostream>
#include "Enemy.h"
using namespace std;

void show_num(int* ptr){
        for (int i = 0; i < sizeof(ptr)/sizeof(ptr[0]); i++){
            cout << *(ptr+i) << endl;
        }
    }

int main() 
{
    int arr[2] = {1, 2};
    show_num(arr);

    bool v = 1;

    Enemy enemies[10];

    /*
    for ( int i = 0; i < 10; i++){
        cout << enemies[i].health << endl;
    }
    */
    if (v) {
        cout << !v << endl;
    }
    

    return 0;
}
