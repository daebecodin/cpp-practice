/*
 * Created by imdem on 3/17/2026.
*/

#include <iostream>
#include <typeinfo>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "auto initialization required",
        "Determine whether auto can declare a variable without an initializer."
      );

    inputs({
        "No Inputs",
        "Objects Involved: { auto a, auto b }"
    });

    pipeline_begin();
    stage("Pre-State");
    auto a = 420;
    auto &ti = typeid(a);


    // auto b; // compile error; requires an initializer
    cout << "auto does not name a fixed type by itself." << '\x0a';
    cout << "auto needs an initializer to deduce a type." << '\x0a';

    stage("Comparisons");
    kv("Possible Reading 1: ", "auto can stand alone like int."); // false
    kv("Possible Reading 2: ", "auto needs an initializer to supply the deduced type."); // true
    blank();

    stage("Operations");
    kv("Step 1: ", "Examine whether each declaration gives the compiler enough information to deduce a type.");
    kv("Step 2: ", "For test A, deduce the type of a from 420.");
    kv("Step 3: ", "For test B, check whether auto has an initializer.");
    kv("Step 4: ", "Resolve which declarations are valid.");
    blank();

    stage("Post-Stage");
    kv("a -> ", "valid if deduction can happen, invalid if not.");
    kv("b -> ", "no initializer, no deduction."); // no type becuase its nor provided an initializer
    blank();

    stage("Compile-Time Checks");
    kv("a -> ", a ); //  compiles
    kv("b -> ", "fails");
    kv("type of a -> ", ti.name());
#if 0
    auto b; //failed compilation
#endif

    classify({
        "Well-Defined: auto a initialized to 420; deduces a to int.",
        "Ill-Formed: auto b; without an initializer no deduction can occur.",
        ""
    });

    rule({
        "auto is a deduction, not a complete standalone type.",
        "variables declared with auto must be initialized.",
        ""
    });
    return 0;
}

