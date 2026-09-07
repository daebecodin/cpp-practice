/*
 * 
 */

#include "pch.h"



int main() 
{
    /*
     * Array Basics
     */

    unsigned cnt = 42; // array dimensions must be greater than zero
    constexpr unsigned sz1 = 42; // array dimensions but be known at compile time

    int arr[10]; // an array of 10 int;
    int *parr[sz1]; // an array of 42 pointers to int
    //std::string bad[cnt]; error because an arrays dimension must be a constexpr
    //std::string strs[get_size()]; works if the function returns a constexpr

    /*
     * Explicitly Initializing Array Elements
     * - we can omit dimension
     * - knows based on initializer list
     * - uninitialized elements will value initialized
     */
    const unsigned sz2 = 3;

    int ial[sz1] = {0, 1, 2}; // an array of 3 ints, 0,1,2
    int a2[] = {0, 1, 2}; // an array of dimension 3
    int a3[5] = {0, 1, 2}; // a3[] = {0,1,2,3,0,0}
    std::string a4[3] = {"hi", "bye"}; // a4[] = {"hi", "bye", ""}
    //int a5[2] = {0, 1, 2}; // error; initializer list exceeds dimension

    /*
     * Character Strings
     * 
     * character literal ending null terminator is copied into the array along with the characters in the literal
     */

    char a6[] = {'C', '+', '+'}; // list-init; no null
    char a7[] = {'C', '+', '+', '\0'}; //list-init; explicit null;
    char a8[] = "C++"; // null-terminator added automatically
    //const char[6] = "Daniel"; // error; not space for null-terminator

    /*
     * No Copy or Assignment
     */

    int a9[] = {0,1,2,3,4,5,6,7,8,9}; // int array of dimension 3
    //int badarr[] = a9; // error; cannot initialize one array with another
    //badarr = a9; // error; cannot assign one array to another

    /*
     * Complicated Array Declarations
     * 
     * - array of pointers
     * - pointer array
     * 
     * Read definition from inside-out
     */

    int *ptrs[10]; //ptrs is an array of 10 pointers to int
    //int &refs[10] = // error; cannot create an array of references
    int (*Parray) [10] = &a9; // Parray points to an array of 10 int
    int (&Rarray) [10] = a9; // Rarray now refers to an array of 10 int









    

    return 0;

}

