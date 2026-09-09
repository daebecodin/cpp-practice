/*
 * 
 */

#include "pch.h"
using std::cin, std::cout;
using std::string;
using std::vector;
using std::size_t;


int main() 
{
    string getCount("How many initialized elements do you want in your vector?: ");
    cout << getCount;

    unsigned int count {};
    cin >> count;

    vector<int> v(20);
    for (size_t i = 0; i < count; ++i)
    {
        v[i] = i;
    }

    string printV("\nYour initialized vector\n");
    cout << printV;

    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;

}
