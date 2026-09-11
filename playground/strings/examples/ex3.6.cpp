#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

using std::cin, std::cout, std::getline, std::endl, std::string, std::istringstream;


int main() 
{
    string s;
    if(getline(cin, s)) {
    cout << s << endl;
    for(char &c : s) {
            c = 'x';
            cout << c;
        }
    }
    return 0;
}
 
