#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using std::cin, std::cout, std::getline, std::endl, std::string, std::istringstream;
typedef string::size_type string_t;

void toHex(string& str);

int main() 
{
    string line;
    toHex(line);
    return 0;

}

void toHex(string& str) {
    const string hexDigits = "0123456789ABCDEF"; // hex values to chose from

    cout    << "Enter a series of numbers between 0 ans 15" 
            << " separated by a spaces. Hit ENTER when finished: "
            << endl;

    string line;
    if (getline(cin , line)) { // read line
        istringstream iss(line);
        string_t n;
        while (iss >> n) {
            if (n < hexDigits.size()) { // check bounds
            str += hexDigits[n]; // append the corresponding char hex code
            }
        }
        cout << "Your resulting hex codes are " << str << endl;
    }

}
