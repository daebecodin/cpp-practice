#include <iostream>
#include <string>
#include <cctype>
using std::endl, std::cout, std::cin, std::string, std::getline;

int main() 
{
    typedef string::size_type size_t;

    string s;
    if (getline(cin, s)) {
        cout << s << endl;
        for (auto &c : s) {
            if (!ispunct(c)) {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;

}

