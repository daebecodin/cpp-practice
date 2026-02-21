/*
 * Created by Durand Dyer-Branch on 2/21/26.
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