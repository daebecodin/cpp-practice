#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() 
{
    string a, b, c;
    cin >> a >> b >> c;

    string concat = a + b + c;
    string separate = a + " " + b + " " + c + " ";

    cout << concat << endl;
    cout << separate << endl;
    
    return 0;

}
