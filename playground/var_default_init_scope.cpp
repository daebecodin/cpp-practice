/*
 * Created by Durand Dyer-Branch on 3/2/26.
 *
 * Global vs local built-in variables 
*/
#include <iostream>
#include <string>
using namespace std;

int globalInt; // should be initialized to 0
string globalString; // should be initialized to an empty string(implementation-defined: UB)


int main()
{
    int localInt; // should be uninitialized
    string localString; // should be an uninitialized empty string

    cout << "Global Variables" << endl;
    cout << globalInt << endl;
    cout << globalString.size() << endl;

    cout << "Local Variables" << endl;
    cout << localInt << endl;
    cout << localString.size() << endl;
}