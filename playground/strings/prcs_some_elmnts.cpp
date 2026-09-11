#include <iostream>
#include <string>
#include <cctype>
using std::cin, std::cout, std::endl, std::string, std::getline, std::boolalpha;

bool isEmpty(string& str);
void firstToUpper(string& str);
void capTilBreak(string& str);

/*
 * Sometimes we want to access a specific number of string elements or access until a condition is met
 * To do do, we can use a subscript; []; or an iterator.
 * 
 * [] takes string::size_type so we must deduce the type; returns a reference
 * 
 * value of the subscript must be > 0 and < string.size
 * Ensure the subscript is in range; < string.size()
 */


int main() 
{
    cout << boolalpha;
    string line;
    isEmpty(line);
    firstToUpper(line);
    capTilBreak(line);
    return 0;

}

bool isEmpty(string& str) {
    bool rtn;
    if (getline(cin, str)) {
        if(!str.empty()) {
            rtn = 0;
            cout << rtn << endl;
            return rtn;
        } else {
            rtn = 1;
            cout << rtn << endl;
            return rtn;
        }
    }
    return 0;
}

void firstToUpper(string& str) {
    if (getline(cin, str)) {
        if (!str.empty()) {
            str[0] = toupper(str[0]);
            cout << str << endl;
        }
    }
}

void capTilBreak(string& str) {
    decltype(str.size()) index; // give index type string::size_type

    if (getline(cin, str)) {
       // loop while not at last char and do not not hit a space
        for (index = 0; index != str.size() && !isspace(str[index]); ++index) {
            str[index] = toupper(str[index]); // capitalize current letter
        }
        cout << str << endl;
    }

 }


