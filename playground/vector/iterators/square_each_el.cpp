/*
 * 
 */

#include "pch.h"
using std::string;
using std::vector;
using std::cin, std::cout;

int main() 
{
    string promptMsg("Enter a list of numbers, followed by -1");
    string preMsg("Original Element List");
    string postMsg("Double Element List");

    vector<int> vi;
    cout << promptMsg << ": ";
    int n;
    while (cin >> n && n != -1)
    {
        vi.push_back(n);
    }

    // print original vector
    cout << '\n' << preMsg << '\n';
    for ( auto i = vi.begin(); i != vi.end(); ++i)
    {
        if (i != vi.begin())
        {
            cout << ", " << *i;
        }
        else
        {
            cout << *i;
        }
    }

    // process vector elements
    for (auto it = vi.begin(); it != vi.end(); ++it)
    {
        *it = (*it) * (*it);
    }

    // print processed / squared vector elements gg
    cout << '\n' << postMsg << '\n';
    for ( auto i = vi.begin(); i != vi.end(); ++i)
    {
        if (i != vi.begin())
        {
            cout << ", " << *i;
        }
        else
        {
            cout << *i;
        }
    }
    return 0;

}
