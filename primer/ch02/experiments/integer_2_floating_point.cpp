/*
 *Created by Durand Dyer-Branch on 2/20/26.
 *
 * Integer to double conversion will always result in defined behavior.
 * 32-bit integer conversion will result in an exact representation due to them being within doubles precision capacity.
 * Larger integer types(64-bit) may lose precision if they exceed the doubles precision capacity(53-bits)
 *
*/


#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x;
    double d;

    cout << boolalpha;
    cout << "Integer -> Double Conversion" << "\n";
    x = 0;
    d = x;
    cout << x << " -> " << d << "\n";

    x = 1;
    d = x;
    cout << x << " -> " << d << "\n";

    x = -1;
    d = x;
    cout << x << " -> " << d << "\n";

    x = 1234567;
    d = x;
    cout << x << " -> " << d << "\n";

    x = numeric_limits<int>::max();
    d = x;
    int back = d;
    cout    << x << " -> " << d
            << " -> " << back
            << " | equal? " << (back == x)
            << "\n";

    x = numeric_limits<int>::min();
    d = x;
    back = d;
    cout    << x << " -> " << d
            << " -> " << back
            << " | equal? " << (back == x)
            << "\n";




}