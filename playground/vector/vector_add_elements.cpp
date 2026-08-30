#include "pch.h"
using std::vector;
using std::string;

/*
 * We don't always know the size, elements/value for our vectors at creation
 * 
 * push_back();
 *  - adds an element to the final index of a vector at run-time
 */

vector<int> addInt() 
{ 
    vector<int> numbers;

    int size{};
    std::cout << "How many elements?: ";
    std::cin >> size;
   
    for (int i = 0; i < size; ++i) {
        int n{};
        std::cout << "Enter an int for index " << i << ": ";
        std::cin >> n;
        numbers.push_back(n);
    }

    return numbers;
}

vector<string> addString()
{
    vector<string> words;

    int size{};
    std::cout << "How many strings?: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) 
    {
        string word;
        std::cout << "Enter a word for index " << i << ": ";
        std::cin >> word;
        words.push_back(word);

    }

    return words;
}

int main() 
{
    vector<int> v1 = addInt();
    vector<string> v2 = addString();
    std::cout << "in main" << '\x0a';

    int i{};

    for (int &n : v1)
    {
        std::cout << i << ": " << n << '\x0a';
        ++i;
    }

    i = 0;

    for (string &s : v2)
    {
        std::cout << i << ": " << s << '\x0a';
        ++i;
    }

    return 0;

} 
