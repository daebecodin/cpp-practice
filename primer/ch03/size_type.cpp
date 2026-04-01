#include <iostream>
#include <string>
using std::string, std::cin, std::cout, std::getline;

int main() 
{
    /*
     * the size of a strng returns std::size_type
     * the tyoe is unsigned
     *
     * preferable use auto or decltype to avoid writing out full type
     */ 
    
    string line;

    while (getline(cin, line)) {
        if (!(line.empty())) {
            cout << line << '\x0a';
            auto len = line.size();
            cout << len << '\x0a';
        }
    }
}
