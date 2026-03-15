/*
 * Created by imdem on 3/15/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
      cout << boolalpha;

    header(
      "typedef alias type",
      "Determine whether a typedef alias behaves like a full type name or like a raw text substitution."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { typedef int *pint, pint p1, const pint p2 }"
    });

    pipeline_begin();
    stage("Pre-State");
    int x = 42; // plain int
    int y = 7; // plain int

    typedef int *pint; // type alias; pointer to int
    kv("typedef int ", "*int");

    pint p1 = nullptr; // pointer to int; points to nothing
    kv("pint p1 = ", "nullptr");

    const pint p2 = &y; // const pointer to int; points to nothing
    kv("const pint p2 = ", "nullptr");



    p1 = &x; // pointer to int; hold x
    kv("p1 -> ", p1);
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "const applies to the alias type as a whole."); // should be this
    kv("Possible Reading 2: ", "const applies to the pointed-to int.");

    stage("Operations");
    kv("Step 1: ", "substitute the alias first (pint -> int*).");
    kv("Step 2: ", "for p1 as a int*");
    kv("Step 3: ", "apply const to the complete aliased type in p2."); // becomes a pointer to an int
    kv("Step: 4 ", "resolve the final type of p2."); // should be a const pointer to an int
    blank();

    stage("Post-State");
    kv("p1 has type -> ", "int*");
    kv("p2 has type -> ", " const pointer to int");
    blank();

    stage("Compile-Time Checks");
#if 0
    p2 = &y;
#endif
    kv("p2 = &y -> ", "const pointer cannot be assigned after initialization.");
#if 1
    *p2 = 9;
    kv("*p2 = ", *p2);
#endif
    kv("*p2 = 9 -> ", "allowed bc the pointed to object is still non-const");

    classify({
        "Well-Defined: pint p1 declares p1 as int*.",
        "Well-Defined: const ping p2 declares p2 as a int* const.",
        "Well-Defined: *p2 = 9; modifies the non-const pointed to object",
        "Ill-Formed: p2 = &y; attempts to assign to a const pointer.",
    });

    rule({
        "A typedef names a complete type.",
        "const applied to a pointer alies makes the pointer const.",
        "const pint means int* const, not const int*."

    });
    return 0;
}
