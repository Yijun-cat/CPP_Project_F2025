#include <iostream>
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

    return 0;
}
