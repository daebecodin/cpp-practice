/*
 * 
 */

#include "pch.h"
using std::string;
using std::cin, std::cout;

int main() 
{

    int arr[] = {1, 2, 3, 4};

    int* beg = arr; // the array returns a pointer to index 0
    int* beg1 = &arr[0]; // direct access to the first element

    int* end = &arr[4]; // nonexistent index; can only read its address; off the end pointer

    for (int* b = arr; b < end; ++b)
    {
         if (b == arr)
         {
            cout << *b;
         } 
         else  
         {
            cout << ", " << *b;
         }
    }

    return 0;

}
