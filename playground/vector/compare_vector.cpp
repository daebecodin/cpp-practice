/*
 * 
 */

#include "pch.h"
using std::cout, std::string, std::vector;
using std::begin, std::end;

int main() 
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,3};

    string header("Your Vectors\n");
    cout << header;

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
    cout << '\n';

    bool areEqual = true;
    auto e = v1.end();
    int start = v2.end() - v2.begin();

    for (auto b = v1.begin(); b != e; ++b)
    {
        if (*b != v2[start] )
        {
            areEqual = false;
            break;
        }
    }

    if (areEqual) 
    {
        cout << "equal";
    }
    else
    {
        cout << "not equal";
    }

    return 0;

}
