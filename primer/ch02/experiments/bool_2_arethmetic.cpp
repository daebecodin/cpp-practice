//
// Created by Durand Dyer-Branch on 2/20/26.
//


#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;
    int i;
    double d;
    unsigned u;

    cout << "True" << endl;
    bool b1 = true;
    i = b1;
    cout << b1 << " -> " << i << "\n";
    d = b1;
    cout << b1 << " -> " << d << "\n";
    u = b1;
    cout << b1 << " -> " << u << "\n";
    cout << endl;


    cout << "False" << endl;
    bool b2 = false;
    i = b2;
    cout << b2 << " -> " << i << "\n";
    d = b2;
    cout << b2 << " -> " << d << "\n";
    u = b2;
    cout << b2 << " -> " << u << "\n";


    return 0;
}