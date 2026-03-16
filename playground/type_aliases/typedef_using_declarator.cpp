/*
 * Created by Durand Dyer-Branch on 3/15/26.
*/
#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

typedef int *pint; // type alise for a pointer to int
using pint2 = int*; // type alias for pointer to int

int main()
{
    cout << boolalpha;
    header(
      "typedef declarator",
      "Determine whether declarator shape still matters after a typedef alias has already formed a type"
    );

    inputs({
        "No Inputs",
        "Objects Involved { typedef int *pint, int value, pint p, pint *pp }"
    });

    pipeline_begin();
    stage("Pre-State");
    int value = 10; // int initialized to 10

    pint p = &value;
    pint2 *pp = &p; // pointer -> pointer to int -> points to p

    kv("pint -> ", "alias for int*");
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "pint *pp is a pointer to a pointer to an int"); // should be this one
    kv("Possible Reading 2: ", "pint *pp is treated as another pointer to int");
    blank();

    stage("Operations");
    kv("Step 1: ", "substitute  the alias first: pint -> int*.");
    kv("Step 2: ", "form p as int*.");
    kv("Step 3: ", "apply the declarator to pp.");
    kv("Step 4: ", "resolve the final type of pp");
    blank();

    stage("Post-State");
    kv("p -> ", "type int*");
    kv("pp -> ", "type int**");
    blank();

    stage("Compile-Time Checks");
    int *raw = p; // int**
    kv("int *raw = p -> ", "compiles");
#if 0
    int *raw2 = pp; // cannot initialize int* with int**; if raw was int** then this would be valid
#endif
    kv("int *raw2 = pp -> ", "fails");

    *pp = nullptr; // valid because  *pp is type int*; we can point to nullptr
    kv("*pp = nullptr -> ", "compiles");

    classify({
        "Well-Defined: pp is a int**.",
        "Well-Defined: an variable of type int* can use p (int*) as an initializer.",
        "Well-Defined: *pp = nullptr assigns null ptr to int*.",
        "Ill-Formed: using a int** as an initializer for an int*; lhs != rhs."
    });

    rule({
        "A typedef builds an alias first.",
        "The declarator is applied after that.",
        "So pint *pp becomes int**."
    });
    return 0;
}