/*
 * Created by Durand Dyer-Branch on 2/21/26.
 *
 * Signed integer overflow is undefined behavior in c++. The compiler
 * may assume that it never occurs
 * Just because wraparound happens during overflow on one system, doesn't guarantee it will happen
 * on another.
 * Due to this behavior, the compiler can perform aggressive optimizations that rely on the absence of overflow
*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x;

    x = numeric_limits<int>::max();
    x = x + 1;
    cout << x << '\n';

}