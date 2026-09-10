/*
 * 
 */

#include "pch.h"
using std::cout, std::string;

int main() 
{
    constexpr int sz = 10;
    int arr[sz] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* b = arr; // points to element[0]
    int* e = b + 10; // points to one past last; handle for end
    int* e2 = arr + 10; // use with caution; do not dereference

    int i = 0;
    while (b < e)
    {
        cout << *b ; //dereferencing the current position
        ++b;

    }

    int mid = sz / 2;

    int m = *(arr + mid); // dereferencing the pointer after the arithmetic

    cout << '\n' << m;


    return 0;


}
