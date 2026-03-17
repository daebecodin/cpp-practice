/*
 * Created by Durand Dyer-Branch on 3/17/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main ()
{
    header(
      "auto multi declaration",
      "Determine whether multiple variables in one auto statement must agree on one deduced type."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { auto a = 420, b = 69; auto c = 42, d = 3.14; }"
    });
    //test a
    auto a = 420, b = 69;

    // test b
    // auto c = 67, d = 21.0;

    pipeline_begin();
    stage("Pre-State");
    kv("auto -> ", "deduces a type from the the initializer");
    kv("declaration -> ", "one base type");
    blank();

    stage("Comparisons");
    kv("Rule 1: ", "each variable in one auto declaration can deduce a completely unrelated type base type"); // false
    kv("Rule 2: ", "all variables in one auto declaration must agree on one deduced base type."); // true
    blank();

    stage("Operations");
    kv("Step 1: ", "Examine test a and deduce the type from each initializer."); // int, int
    kv("Step 2: ", "Check whether both declarators agree on one base type."); // they do
    kv("Step 3: ", "Examine test b and deduce the type from each initializer."); // int, double
    kv("Step 4: ", "Check whether those declarators agree on one base type."); // they do not
    blank();

    stage("Post-State");
    kv("a and b -> ", "types deduced as int; matching initializer types.");
    kv("c and d -> ", "ill-formed declaration; conflicting initializer types.");
    blank();

    stage("Compile-Time Checks");
    kv("Test a -> ", "compiles");
    kv("a -> ", a);
    kv("b -> ", b);
    kv("a and b -> ", "int");
    kv("Test b -> ", "fails");

    classify({
        "Well-Defined: auto a = 420, b = 69; both deduce to int.",
        "Ill-Formed: auto c = 42, d = 21.0; the declaration requires both int and double on the same deduced base type ",
        ""
    });

    rule({
        "One declaration has one base type",
        "In a single auto declaration, all initializers must agree on the same deduced base type ",
        ""
    });
    return 0;
}