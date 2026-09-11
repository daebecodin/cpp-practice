#include <iostream>
#include <string>
#include <cctype>
using std::cin, std::cout, std::endl, std::getline, std::string;

int main() 
{
    string str;

    while (getline(cin, str)) {
        if (str.empty()) {
            cout << "string empty" << endl;
        } else {
        for (auto &c : str) {
            c = toupper(c);
            cout << c;
            }
            cout << endl;
            return 0;
        }

    }

}
