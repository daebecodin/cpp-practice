/*
 * Created by Durand Dyer-Branch on 3/24/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{

    header(
      "auto vs decltype",
      "determine how auto and decltype defer when given given the \"same-looking\" initializer source"
    );

    inputs({
        "No Inputs",
        "Objects-Involved: { int i = 42, int &ri = i, const int ci = i, auto a = ri, decltype(ri) b = i, auto c = ci, decltype(ci) d = i }"
    });
    int i = 420;
    int &ri = i;
    const int ci = i;
    auto a = ri; // plain auto drops ref and const; int
    decltype(ri) b = i; // prserves type exactly;int&
    auto c = ci; // plain aut drops ref and const; int
    decltype(ci) d = i; // preserves type exactly; const int

    pipeline_begin();
    stage("Pre-State");
    kv("ri -> ", "reference to i");
    kv("ci -> ", "const int w/value copy of i");
    kv("auto -> ", "deduces from initializer");
    kv("decltype(name) -> ", "reports the type exactly");
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "auto and decltype behave similarly when given the same source");
    kv("Possible Reading 2: ", "auto normalizes from initialization while decltype preserves the declared type form");
    blank();

    stage("Operations");
    kv("Step 1: ", "Evaluate auto a = ri");
    kv("Step 2: ", "Evaluate decltype(ri) b = i");
    kv("Step 3: ", "Evaluate auto c = ci");
    kv("Step 4: ", "Evaluate decltype(ci) d = i");
    blank();

    stage("Post-State");
    kv("a -> ", "int");
    kv("b -> ", "int&");
    kv("c -> ", "int");
    kv("d -> ", "const int");
    blank();

    stage("Compile-Time Checks");
    kv("auto a = ri -> ", "compiles -> int");
    kv("decltype(ri) b = i -> ", "compiles -> int&");
    kv("auto c = ci -> ", "compiles -> int");
    kv("decltype(ci) d = i -> ", "compiles -> const int");

    classify({
        "auto a = ri; declared as int",
        "decltype(ri) b = i; declared as int&",
        "auto c = ci; declared as int",
        "decltype(ci) d = i; declared as const int"
    });

    rule({
        "auto normalizes from initialization.",
        "decltype(name) preserves the declared type exactly.",
        "auto strips top-level const/reference; decltype reports exactly."
    });
    return 0;
}