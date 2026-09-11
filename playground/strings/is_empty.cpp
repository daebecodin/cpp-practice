#include <iostream>
#include <string>
using std::cin, std::cout, std::string, std::getline;

int main() 
{
    /*
     * the .empty function returns a bool to whether the given sring was empty
     */ 

    string line;
    while (getline(cin, line)) {
        if (!(line.empty())) {
            cout << line << '\x0a';
        }
    }
    return 0;

}
