#include "pch.h"
using std::vector;

int main() 
{
    
    // Default Initialization -> 0 elements
    vector<int> v1; 

    // Direct-Initialization using copy
    vector<int> v2(v1);

    // Copy Initialization
    vector<int> v3 = v1;

    // Direct-Initialization: n copies of val
    vector<int> v4(6,7);

    // Direct-Initialization: n elements each 0 initialized
    vector<int> v5(67);

    // Direct-List-Initialization
    vector<int> v6{1,2,3,4,5};

    // Copy-List-Initialization (same as v6)
    vector<int> v7 = {1,2,3,4,5};


    return 0;

}


