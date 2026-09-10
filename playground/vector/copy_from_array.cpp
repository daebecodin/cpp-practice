/*
 * Copying elements from an array to vector
 */

#include "pch.h"
using std::string, std::cout, std::vector, std::begin, std::end;

int main() 
{
    int a[3] = {1,2,3};

    vector<int> v1(begin(a), end(a)); // copies index 0-2
    vector<int> v2(a + 1, a + 3); // copies index 1-2

    cout << "a: ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << '\n';

    cout << "v1: ";
    for (int i : v1)
    {
        cout << i << " ";
    }
    cout << '\n';

    cout << "v2: ";
    for (int i : v2)
    {
        cout << i << " ";
    }

    return 0;

}
