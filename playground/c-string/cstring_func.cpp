#include "pch.h"

using std::strlen, std::strcmp, std::strcat, std::strcpy;
using std::cin, std::cout, std::string, std::boolalpha;
 
int main() {
    const char cs1[] = "string 1";
    const char cs2[] = "string 2";

    string displayStringsTxt("Your strings\n");
    cout << displayStringsTxt;
    cout << cs1 << '\n' << cs2 << '\n';

    string displayComparisonTxt("Are they the equal?\n");
    cout << displayComparisonTxt;
    cout << boolalpha;

    if (strcmp(cs1, cs2) == 0)
    {
        cout << true;
    } 
    else {
        cout << false;
    }
    
    return 0;
}
