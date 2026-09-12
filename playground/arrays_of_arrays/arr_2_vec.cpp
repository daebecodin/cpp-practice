/*
 * Write a program to initialize a vector from an array of
 * ints
 */
#include "pch.h"
using std::vector;
using std::begin, std::end;
using std::cout;

int main() 
{

    int ia[] = { 1, 2, 3, 4, 5};

    int* iab = ia;
    int* iae = ia + 5;

    vector<int> v(iab, iae);

    for (auto it = v.cbegin(); it < v.end(); ++it)
    {
        if (it != v.begin())
        {
            cout << ", " << *it;
        }
        else 
        {
            cout << *it;
        }
    }
    


    return 0;

}


