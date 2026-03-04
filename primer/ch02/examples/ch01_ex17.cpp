//
// Created by imdem on 3/3/2026.
//

#include <iostream>
using namespace std;

int i, &ri = i;
int main()
{
    i = 5, ri = 10;
    cout << i << " " << ri << endl;
}