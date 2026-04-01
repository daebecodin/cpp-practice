#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() 
{
    string a, b;
    cin >> a >> b;

    bool compare1 = ( a == b);
    bool compare2 = a > b;

    cout << (compare1 == true ? "same" : "not same") << endl;
    cout << (compare2 == true ? "a is larger" : "b is larger") << endl;

    return 0;

}
