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
    unsigned int u = 0;
    u = u -1;
    cout <<"Using 0" << '\n';
    cout << u << '\n' << '\n';


    u = numeric_limits<unsigned int>::max();
    u = u + 1;
    cout << "Using System Max" << '\n';
    cout << u << '\n';


}