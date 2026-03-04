//
// Created by imdem on 3/3/2026.
//

#include <iostream>
using namespace std;

int main ()
{
    int i = 44;
    int *ip = &i;
    cout << "address of i -> " << ip << '\x0a';
    cout << "value of i -> " << i << '\x0a' << '\x0a';

    cout << "value of *ip -> " << *ip << '\x0a' << '\x0a';

    *ip = 54;
    cout << "new value of *ip -> " << *ip << '\x0a';

    int i2 = 66;
    ip = &i2;
    cout << "new address stored in *ip -> " << ip << '\x0a';
}