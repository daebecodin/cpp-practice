/*
 * Created by Durand Dyer-Branch on 3/2/26.
 * brace-init vs paren-init with floating → int
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Different Initializers\x0a";
    double d1{3.14};
    double d2 = 2.23;
    double d3(1.9);

    cout << d1 << '\x0a' << d2 << '\x0a' << d3 << '\x0a' << '\x0a';

    cout << "Safe vs Unsafe Narrowing\x0a";
    double f1 = 44.4;
    float f2 = 1.5 + 1.5;
    float f3 = 4.44;

    long double a{f1};
    double b{f2};
    double c{f3};

    // works due to non narrowing
    cout << a << '\x0a' << b << '\x0a' << c << '\x0a' << '\x0a';

    // int a{f1};
    // int b{f2};
    // int c{f3};


}