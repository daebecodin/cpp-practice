#include <iostream>
#include <string>
using std::string,std::getline, std::cin, std::cout;

int main() 
{
    string line;

    while (getline(cin, line)) {
        if(line.size() < 80) {
            cout << line << '\x0a';
        }
            return 1;
    }
    return 0;

}
