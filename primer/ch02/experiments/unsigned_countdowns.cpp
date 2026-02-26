/*
 * Created by Durand Dyer-Branch on 2/21/26.
 *
 * Unsigned values are never negative, so a condition like i > 0, where i is an unsigned it,
 * will always be true.
 * In a countdown loop, a decrement past 0 wraps to unsigned int maximum, making the loop infinite.
 * The correct unsigned countdown needs a condition that becomes false before the wraparound such as i > 0
 * or i-- > 0.
*/

#include <iostream>
using namespace std;

int main()
{
    for (unsigned int i = 10; i-- > 0;) {
        cout << "hello" << '\n';
    }
}
