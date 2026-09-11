/*
 * 
 */

#include "pch.h"
using std::vector, std::cout;
using std::begin, std::end;

int main() 
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int* ab = arr;
    int* ae = end(arr);


    vector<int> v ( ab, ae );
    vector<int> subv ( arr + 1, arr + 4);

    auto vb = v.begin();
    auto svb = subv.begin();

    for (auto it = v.begin(); it < v.end(); ++it)
    {
        if (it != vb) 
        {
            cout << ", " << *it;
        }
        else
        {
            cout << *it;
        }
    }
    cout << '\n';

    for (auto it = subv.begin(); it < subv.end(); ++it)
    {
        if (it != svb)
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

