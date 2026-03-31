#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::getline;


/*
 * To read an entire line, including white space, we use getline().
 * 
 * getline(input-stream, string)
 */

int main() 
{
    string line;
    while (getline(cin, line)) {
        cout << line << '\x0a';
        return 0;
    }

    return 0;

}
