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

    bool firstElement{true}; // marker for the first element
    for (auto n = v.cbegin(); n != v.cend(); ) 
    {
        int sum = *n; // adds current element to pair sum; created fresh each run
        ++n; // move iterator to second element in pair

        if (n != v.cend())  // if a second element exists
        {
            sum += *n; // add the second element
            ++n; // move iterator to the beginning of the next pair
        }

        if (!firstElement) // all elements after the first
        {
            cout << ", ";
        }

        cout << sum; // print pair sum

        firstElement = false; // first iteration over; later sums need a comma before them
    }

    cout << '\n';
    return 0;

}
