
/*
 * prove that arrays decay to pointers
 */

#include "pch.h"
using std::cout;
using std::boolalpha;

int main() 
{
    // create 1 array
    int arr1[] = {1, 2, 3, 4, 5};

    // 2 raw pointers to array to first elements
    int* p1 = arr1;
    int* p2 = &arr1[0];

    // modify an element from one access path
    p2[2] = 67;
    cout << arr1[2] << '\n';

    // print both arrays
    cout << p1 << '\n' << p2 << '\n';


    // create a pointer using auto
    auto a = arr1; // pointer to first element

    // create type alias using decltype()
    decltype(arr1) copy = {5, 6, 7, 8};

    // confirm type
    cout << boolalpha;
    cout << std::is_pointer_v<decltype(arr1)> << '\n';
    cout << std::is_array_v<decltype(copy)> << '\n';


    return 0;

}
