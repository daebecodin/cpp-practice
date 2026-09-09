
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

    // both pointers point to the arrays first element
    int* p1 = arr1;
    int* p2 = &arr1[0];

    // modify the array through a pointer
    p2[2] = 67;
    cout << arr1[2] << '\n';

    // both pointers should contain the same address
    cout << p1 << '\n' << p2 << '\n';


    // auto sees the array converted as a pointer
    auto a = arr1; // pointer to first element

    // decltype preserves the array type
    decltype(arr1) copy = {5, 6, 7, 8};

    // confirm type
    cout << boolalpha;
    cout << "Is a pointer?: " 
         << std::is_pointer_v<decltype(a)> << '\n';

    cout << "Is an array?: " 
         << std::is_array_v<decltype(copy)> << '\n';


    return 0;

}
