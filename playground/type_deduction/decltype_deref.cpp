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
     "decltype dereference",
     "Determine whether decltype(p) and decltype(*p) produce the same type"
   );

    inputs({
        "No Inputs",
        "Objects Involved: { int i = 42, int *p = &i, decltype(p) a = p, decltype(*p) b = i }"
    });
    int i = 420;
    int *p = &i;
    decltype(p) a = p; // type pointer to int
    decltype(*p) b = i; // type int

    pipeline_begin();
    stage("Pre-State");
    kv("p -> ", "type int*");
    kv("*p -> ","lvalue expression referring to i");
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "both decltype(p) and decltype(*p) produce the pointed to type.");
    kv("Possible Reading 2: ", "decltype(p) reports the pointer type; decltype(*p) follows expression category and can produce a reference type.");
    blank();

    stage("Operations");
    kv("Step 1: ", "Evaluate decltype(p).");
    kv("Step 2: ", "Evaluate decltype(*p).");
    kv("Step 3: ", "Resolve the final types of a and b.");
    kv("Step 4: ", "Check whether both lines compile.");
    blank();

    stage("Post-State");
    kv("a -> ", "int*");
    kv("b -> ", "int&");
    blank();

    stage("Compile-Time Checks");
    kv("decltype(p) a = p -> ", "compiles");
    kv("decltype(*p) b = i -> ", "compiles");
    kv("type of a -> ", "int*");
    kv("type of b -> ", "int&");

    classify({
        "Well-Defined: decltype(p) a = p; declares a as an int*",
        "Well-Defined: decltype(*p) b = i; declares b as an int&",
        ""
    });

    rule({
        "decltype(p) reports the pointer type.",
        "decltype(*p) sees an lvalue expression and produces a reference.",
        "dereferencing makes decltype produce T&."
    });
    return 0;
}