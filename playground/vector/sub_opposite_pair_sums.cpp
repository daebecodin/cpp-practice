#include "pch.h"
using std::cin, std::cout;
using std::vector;
using std::string;
using std::size_t;

int main() 
{
    vector<int> nList;
    int nInput{};

    cout << "Enter integer list: ";
    while (cin >> nInput && nInput != -1)
    {
        nList.push_back(nInput);
    }

    if (nList.size() < 2) {
        cout << "Not enough inputs";
        return 0;
    }

    cout << "=== Summed Pairs ===\n";
    size_t i{};
    int pairCount{1};
    for (i = 0; i < nList.size() / 2; ++i)
    {
        int a = nList[i];
        int b = nList[nList.size() - 1 - i];
        int sum = a + b;

        cout << "Pair " << pairCount << ": " << sum << '\n';
        pairCount++;
    }


    return 0;

}
