//
// Created by Durand Dyer-Branch on 2/20/26.
//



#include <iostream>
#include <limits>
using namespace std;

int main()
{
    double d;
    int i;

    cout << "Double -> Integer" << endl;

    d = 3.14;
    i = d;
    cout << d << " -> " << i << "\n";

    d = -3.14;
    i = d;
    cout << d << " -> " << i << "\n";

    d = 0.99;
    i = d;
    cout << d << " -> " << i << "\n";

    d = -0.99;
    i = d;
    cout << d << " -> " << i << "\n";

    d = 42.0;
    i = d;
    cout << d << " -> " << i << "\n";

    d = 1e9;
    i = d;
    cout << d << " -> " << i << "\n";

    d = numeric_limits<int>::max() - 10;
    i = d;
    cout << "Near Max" << "\n";
    cout << d << " -> " << i << "\n";

    d = numeric_limits<int>::max();
    i = d;
    cout << "Max" << "\n";
    cout << d << " -> " << i << "\n";

    d = numeric_limits<int>::max() * 2.0;
    i = d;
    cout << d << " -> " << i << "\n";








}