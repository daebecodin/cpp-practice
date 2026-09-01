/*
 * 
 */


#include "pch.h"
using std::string;
using std::cin, std::cout, std::getline;
using std::vector;
using std::size_t;
using std::toupper;
int main() 
{

    cout << "Enter a full scentence: ";
    string text{};
    getline(cin, text);
    for (auto it = text.begin(); it != text.end() && *it != ' '; ++it)
    {
        *it = toupper(*it);
    }

    cout << text;
    return 0;

}
