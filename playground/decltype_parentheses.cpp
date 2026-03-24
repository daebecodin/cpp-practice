/*
 * Created by Durand Dyer-Branch on 3/23/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
       "decltype parentheses",
       "Determine whether adding parentheses changes the type of decltype"
     );

    inputs({
        "No Inputs",
        "Objects Involved: { int i = 42, decltype(i) a = i, decltype((i)) b = i }"
    });
    int i = 420;
    decltype(i) a = i; // reports the exact int type
    decltype((i)) b = i; // expression produces int&

    pipeline_begin();
    stage("Pre-State");
    kv("int i -> ", "has type int");
    kv("(i) -> ", "is a named variable");
    kv("((i)) -> ", "is an lvalue expression");
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "Parentheses do not matter; decltype(i) and decltype((i)) produce the same type.");
    kv("Possible Reading 2: ", "Parentheses change the operand form; decltype(i) reports the exact type, while decltype((i)) follows expression category.");
    blank();

    stage("Operations");
    kv("Step 1: ", "Evaluate decltype(i)");
    kv("Step 2: ", "Evaluate decltype((i))");
    kv("Step 3: ", "Resolve the final types of a and b");
    kv("Step 4: ", "Check whether both declarations compile");
    blank();

    stage("Post-State");
    kv("a -> ", "int");
    kv("b -> ", "int&");
    blank();

    stage("Compile-Time Checks");
    kv("decltype(i) a = i -> ", "compiles");
    kv("decltype((i)) b = i -> ", "compiles");
    kv("type of a -> ", "int");
    kv("type of b -> ", "int&");


    classify({
        "Well-Defined: decltype(i) a = i; declares a as an int",
        "Well-Defined: decltype((i)) b = i; declared b as an int&",
        ""
    });

    rule({
        "decltype(name) reports the declared type (int).",
        "decltype((expr)) follows expression category.",
        "parentheses can change the decltype result."
    });
    return 0;
}