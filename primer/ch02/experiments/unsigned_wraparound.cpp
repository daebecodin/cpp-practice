/*
 * Created by Durand Dyer-Branch on 2/21/26.
 *
 * Signed arithmetic is defined by modulo 2^n, where n is the # of bits of the unsigned type.
 * All overflow & underflow wraparound is defined behavior.
 * The values of unsigned types can never be negative
*/

#include <iostream>
#include <limits>
using namespace std;


int main()
{
    cout << "Unsigned Wraparound\x0a";
    unsigned int u = 2;
    unsigned int u2 = numeric_limits<unsigned int>::max();
    cout <<"Using 0" << '\n';
    cout << "Wraparound to largest representable value of the type\x0a";
    unsigned int u3 = u - 0;
    cout <<u3<< "\x0a";
    cout << u2<< '\x0a';
    unsigned int u4 = u2 + u3;
    cout << u4<< '\x0a';


    u = numeric_limits<unsigned int>::max();
    u = u + 1200;
    cout << "Using System Max" << '\n';


    cout << u << '\n';


}