#include "pch.h"
#include <cctype>
using std::cin, std::cout, std::string, std::vector, std::toupper;

int main() 
{
    string splitString;
    vector<std::string> connectedString;
    
    // read a sequence from cin and store the values in a vector
    while (cin >> splitString) 
    {
        connectedString.push_back(splitString);
    }

    // process the vector
    for (std::size_t i = 0; i < connectedString.size(); ++i) {
        // convert each char
        for (char& c : connectedString[i]) {
            // convert to uppercase
            c = toupper(static_cast<unsigned char>(c));
        }
    }

    // print processed vector
    for (auto& s : connectedString) {
        cout << s << " ";
    }
    return 0;

}

