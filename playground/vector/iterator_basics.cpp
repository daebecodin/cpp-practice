/* Iterators
 * - replacement for subscript indexing in containers
 * - similar to pointers, we get indirect access to the object
 * - when using iterators, that object is an element in a container / character in a string
 * 
 * VALID ITERATORS
 * - denotes an element
 * - denotes a position one past the last element of a container
 * 
 */
#import "pch.h"
using std::cin, std::cout;
using std::string, std::vector;
using std::size_t;




int main() 
{

    vector<int> v;

    // first element or character in v if it exists
    auto b = v.begin(); 

    // off-the-end iterator
    // positioned one slot past the final element or character in v is it exists. all items processed
    auto e = v.end();
    int input{};

    cout << "Add items to vector: ";
    while (cin >> input && input != -1)
    {
        v.push_back(input);
    }

    for (const auto &n : v) {
        cout << n << " ";
    }


    return 0;

}
