//
// Created by Durand Dyer-Branch on 2/12/26.
//

/*
 * Indicate which, if any, of the following output statements are illegal
 */

#include <iostream>

void cmnt1() {
    /*
     * should work bc this is just outputing a string literal
     */
    std::cout << "/*";
}

void cmnt2()
{
    /*
     * should work because this is just outputting a string literal
     */
    std::cout << "*/";
}

void cmnt3()
{
    /*
     * this is illegal because the output operater has no rhs opperand due to the block comment using the delimters
     * there is essentially no given output
     * to fix, all we need to do is provide actual output not between 2 delimiters
     */
    std::cout << /* "/*" */;
}

void cmnt4()
{
    /*
     *`
     */
    std::cout << /*  "*/"  /*  "/*"  */;
}

int main()
{
    cmnt1();
    cmnt2();
    cmnt3();
    cmnt4();
}