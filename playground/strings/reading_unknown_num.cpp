#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;


/*
 * This method does ignored white space.
 * The output string, regardless of spaces, will will be a single string
 */
int main()
{
    string many;

    while (cin >> many) {
        cout << many;

    }
    return 0;

}


