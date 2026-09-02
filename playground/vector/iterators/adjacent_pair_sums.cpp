/*
 * Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements.
 */

#include "pch.h"

using std::vector;
using std::cin, std::cout;
using std::string;

int main() 
{
    string prompt("Enter a sequence of integers, followed by -1: ");
    cout << prompt;

    int n{};
    vector<int> v;

    while (cin >> n && !cin.fail() && n != -1)
    {
        v.push_back(n);
    }

    string ogVecMsg("Original Vector: ");
    cout << ogVecMsg;
    for (auto n = v.begin(); n != v.end(); ++n)
    {
        if (n == v.end() -1)
        {
            cout << ", " << *n << '\n';
        }
        else if (n != v.begin()) 
        {
            cout << ", " << *n;
        }
        else 
        {
            cout << *n;
        }
    }

    string newVecMsg("Modified Vector: ");
    cout << newVecMsg;
    bool first{true};
    for (auto n = v.cbegin(); n != v.cend(); ) 
    {
        int sum = *n;
        ++n;

        if (n != v.cend()) 
        {
            sum += *n;
            ++n;
        }

        if (!first) 
        {
            cout << ", ";
        }

        cout << sum;

        first = false;
    }

    cout << '\n';
    return 0;

}
