#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string, std::getline;

int main() 
{
    string a, b;
    string result;

    cout << "what strings would you like to compare?" << '\x0a';

    cout << "string 1: ";
    getline(cin, a);
    cout << '\x0a';

    cout << "string 2: ";
    getline(cin, b);
    cout << '\x0a';

    if (a > b) {
        result = "a is bigger";
        cout << result;
    } else {
        result = "b is bigger";
        cout << result;
    }
    return 0;

}
