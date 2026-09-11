#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

using std::cin, std::cout, std::getline, std::endl, std::string, std::istringstream;

int main() 
{
    typedef string::size_type string_t;

    string s;
    if(getline(cin, s)) {
        cout << s << endl;
        for (string_t index {0}; index < s.size(); ++index) {
            s[index] = 'x';
        }
        cout << s << endl;
        return 0;
    }

}

