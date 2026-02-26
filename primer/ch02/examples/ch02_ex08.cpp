/*
 * Created by Durand Dyer-Branch on 2/25/26.
 *
 * Using escape sequences, write a program to print 2M followed by a newline.
 * Modify the program to print 2, then a tab, then an M, followed by a newline.
*/

#include <iostream>
#include <string>
using namespace std;

void v1() {
    cout << "Version 1" << "\12";
    cout << "\62" << "\115" << "\12";

}

void v2()
{
    cout << "Version 2" << "\x0a";
    cout << "\x32" << "\x09" << "\x4d" << "\x0a";

}



int main() {
    v1();
    v2();




    return 0;
}