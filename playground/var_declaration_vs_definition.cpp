/*
 * Created by Durand Dyer-Branch on 3/2/26.
 * One definition, multiple declarations (linker behavior)
*/
#include <iostream>
using namespace std;

int globalVar{22}; // variable declaration/ definition
extern int externVar1; // variable declaration
int main()
{
    cout << "global var -> " << globalVar << "\x0a"; // variable declaration
    cout << "extern var -> " << externVar1; // defined at /Users/dmac/c++/cpp-practice/playground/external_definition.cpp


    return 0;
}