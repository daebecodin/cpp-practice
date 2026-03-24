/*
 * Created by Durand Dyer-Branch on 3/22/26.
*/

#include <iostream>
#include "report.h"
#include "type_name.h"
using namespace rpt;
using std::cout, std::boolalpha;

int main()
{
    header(
        "decltype name vs expression",
        "Determine whether decltype(name) and decltype(expression) produce the same type"
      );

    inputs({
        "No Inputs",
        "Objects Involved: { int i = 42, decltype(i) a = i, decltype((i)) b = i }"
    });
    int i = 420; // type of int
    decltype(i) a = i; // names variable
    decltype((i)) b = i; // expression

    pipeline_begin();
    stage("Pre-State");
    kv("i -> ", "hast type of int");
    kv("decltype(i) -> ", "declared variable");
    kv("decltype((i)) b = i -> ", "expression");
    blank();

    stage("Operations");
    kv("Step 1: ", "evaluate decltype(1)");
    kv("Step 2: ", "evaluate decltype((i))");
    kv("Step 3: ", "resolve the final types of a and b");
    kv("Step 4: ", "check whether both declarations compile");

    stage("Post-State");
    kv("a -> ", "int");
    kv("b -> ", "int&");
    blank();

    stage("Compile-Time Checks");
    kv("decltype(i) a = i; compiles -> " ,a);
    kv("decltype((i)) b = i; compiles -> " ,b);
    kv("type of a -> ", type_name<decltype(a)>());
    kv("type of b -> ", type_name<decltype(b)>());

    classify({
        "Well-Defined: decltype(i) a = i defines an int type.",
        "Well-Defined: decltype((i)) b = i defines an int& type.",
        ""
    });

    rule({
        "decltype(name) reports the declared type exactly.",
        "decltype(expr) follows expression category.",
        "lvalue expressions produce T&.",
        "rvalue gives type exactly"
    });
    return 0;
}