#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

using std::cin, std::cout, std::getline, std::endl, std::string, std::istringstream;

int main() 
{
    typedef string::size_type string_t;

    string s;
    if (getline(cin, s)) {
        cout << s << endl;
        string_t index {0};
        while (index !=s.size()) {
            s[index] = 'x';
            ++index;
        }
    cout << s; }
    return 0;
}
