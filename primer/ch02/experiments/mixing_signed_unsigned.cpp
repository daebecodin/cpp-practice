/*
 * Created by Durand Dyer-Branch on 2/21/26.
 *
 * When signed and unsigned ints are used in the same expression, if the unsigned int is of equal or greater rank,
 * the signed operand is converted to unsigned.
 *
 * Negative numbers are now converted module 2^n, n being the number of bits for the type
 *
 * This conversion is dangerous because negative signed values may be converted to large unsigned positive values,
 * leading to a change in comparison and arithmetic meaning.
*/


#include <iostream>
using namespace  std;


int main()
{
    cout << boolalpha;
    int s = -1;
    unsigned int u = 1;
    cout << (s < u) << '\n';



}