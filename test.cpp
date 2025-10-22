#include <iostream>
using namespace std;

int main() 
{
    char arr[] = {};

    cout << sizeof(arr) / sizeof(arr[0]) << endl;

    return 0;
}
