/*
 * Created by Durand Dyer-Branch on 3/20/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "auto declarator shape",
        "Determine whether declarator shape still matters after auto deduces a type"
      );

    inputs({
        "No Inputs",
        "{ int i = 42, int *p = &i, auto x = p, auto *y = p, auto z = *p }"
    });
    int i = 420;
    int *p = &i;
    auto x = p; // pointer to int; keeps shape
    auto *y = p; // pointer to int; keeps shape
    auto z = *p; // int; keeps shape


    pipeline_begin();
    stage("Pre-State");
    kv("Possible Reading 1: ", "auto determines the entire final type by itself.");
    kv("Possible Reading 2: ", "auto deduces a base type, then the declarator still shapes the final type."); // should be this one
    blank();

    stage("Operations");
    kv("Step 1: ", "deduce the base type from p to x");
    kv("Step 2: ", "deduce the base type from p for y, then apply the declarator *");
    kv("Step 3: ", "deduce the base type from *p for z");
    kv("Step 4: ", "x -> int*; y -> int*; z -> int");
    blank();

    stage("Post-State");
    kv("x -> ", "int*");
    kv("y -> ", "int*");
    kv("z -> ", "int");
    blank();

    stage("Compile-Time Checks");
    kv("auto x = p; compiles -> ", *x);
    kv("auto *y = p; compiles -> ", *y);
    kv("auto z = *p; compiles -> ", z);

    classify({
        "Well-Defined: auto x = p; deduces to int*",
        "Well-Defined: auto *y = p; deduces to int, then * declarator forms int*",
        "Well-Defined: auto z = *p; deduces to int"
    });

    rule({
        "auto deduces a base type from the initializer.",
        "the declared declarator is applied after deduction.",
        "alone, auto will not decide the final type of the object.",
        "auto deduces base type, declarator finishes the type."
    });
    return 0;
}