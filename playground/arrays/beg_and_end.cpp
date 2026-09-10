
/*
 * The standard library provides the begin and end functions.
 * begin returns a pointer to the first element of the passed in array
 * end returns a pointer to one past the last element in an array
 */

#include "pch.h"
using std::cout, std::string;
using std::begin, std::end;

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};

    int* b = begin(arr);
    int* e = end(arr);
    return 0;

}
