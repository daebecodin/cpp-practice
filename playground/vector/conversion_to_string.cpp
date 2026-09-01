#include "pch.h"
#include <cctype>
#include <cstddef>
using std::cin, std::cout, std::string, std::vector, std::toupper;

int main() 
{
    string splitString;
    vector<std::string> connectedString;
    
    // read a sequence from cin and store the values in a vector
    cout << "Enter a sequence of strings, separated by spaces: ";
    while (cin >> splitString) 
    {
        connectedString.push_back(splitString);
    }

    // process the vector
    for (std::size_t i = 0; i < connectedString.size(); ++i) 
    {
        // convert each char
        for (char& c : connectedString[i]) 
        {
            // convert to uppercase
            c = toupper(static_cast<unsigned char>(c));
        }
    }

    // print processed vector
    for (std::size_t i = 0; i < connectedString.size(); ++i)
    {
        // print each word
        cout << connectedString[i] << " ";

        // at every 8th word , add \n
        if ((i + 1) % 8 == 0)
        {
            cout << '\n';
        }
    }

    // places a new line if final line doesn't have 8
    if (connectedString.size() % 8 != 0) 
    {
        cout << '\n';
    }
    return 0;
}

