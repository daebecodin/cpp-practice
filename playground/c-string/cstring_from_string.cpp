/*
 * Write a program to define two character arrays initialized
 * from string literals. 
 * Now define a third character array to hold the
 * concatenation of the two arrays. Use strcpy and strcat to copy the two
 * arrays into the third.
 */

#include "pch.h"
using std::cin, std::cout, std::string;
using std::strcpy;
using std::strcat;


int main() 
{
    char cs1[] = "string 1";
    char cs2[] = "string 2";

    constexpr int size = sizeof(cs1) + sizeof(cs2);

    string yourStrings("Your strings\n");
    cout << yourStrings;

    cout << cs1 << '\n' << cs2;

    char bigcs[size];

    string concatStr("\nConcatenated String\n");
    cout << concatStr;

    strcpy(bigcs, cs1);
    strcat(bigcs, " ");
    strcat(bigcs, cs2);

    cout << bigcs;
    return 0;

}
