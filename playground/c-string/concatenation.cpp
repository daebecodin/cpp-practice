/*
 * Write a program to define two character arrays initialized
 * from string literals. 
 * Now define a third character array to hold the
 * concatenation of the two arrays. Use strcpy and strcat to copy the two
 * arrays into the third.
 */

#include "pch.h"
using std::vector, std::cout;

int main() 
{

    // both have explicit null terminators
    char cs1[] = "hello";
    char cs2[] = "world";

    const int sz1 = sizeof(cs1);
    const int sz2 = sizeof(cs2);

    constexpr int concatSize {sz1 + sz2};
    char cs3[concatSize];

    strcpy(cs3, cs1);
    strcat(cs3, " ");
    strcat(cs3, cs2);

    cout << cs3;
}
