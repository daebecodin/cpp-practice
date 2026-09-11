#include <iostream>
#include <string>
using std::string, std::cin, std::getline, std::cout, std::endl;

int main() 
{
    string line;

    while (getline(cin, line)) {
        if (!line.empty()) {
            cout << "loop 1" << '\x0a';
            cout << line << endl;
            break;
        }
    }


    string word;
    while (cin >> word) {
        if (!word.empty()) {
        cout << word << endl;
        }
    }
    
    return 0;
}


