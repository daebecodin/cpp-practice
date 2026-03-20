/*
 * Created by Durand Dyer-Branch on 3/19/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
   "auto const and refs",
   "Determine how plain auto, auto&, and const auto& treat top-level const, low-level const, and reference initializers."
 );

    inputs({
        "No Inputs",
        "Objects Involved: { int i = 42, const int ci = i, int &ri = i, const int &rci = ci, auto a = ci, auto b = ri, auto c = rci, auto &d = i, auto &e = ci, const auto &f = 42 }"
    });
    int i = 42;
    const int ci = i;
    int &ri = i; // alias to i
    const int &rci =ci; // alias to ci

    // Plain auto -> value copies
    auto a = ci;
    auto b = ri;
    auto c = rci; // drops the top level const


    auto &d = i; // forms a reference to the referred to obj
    auto &e = ci; // refencing a const int so the constraints remain
    const auto &f = 42; // forms a const reference; holds a temporary

    pipeline_begin();
    stage("Pre-State");
    kv("ci -> ", "const int");
    kv("ri -> ", "reference to an int bound to i");
    kv("rci -> ", "reference to const int bound to ci");
    blank();

    stage("Comparisons");
    kv("Plain auto -> ", " drops the top level const and reference-ness from the initializer.");
    kv("auto& -> ", "forms a reference, so the referred-to type constraints cary over to the reference built with auto.");
    kv("const auto& -> ", "forms a const reference and can bind to broader initializer forms.");
    blank();

    stage("Operations");
    kv("Step 1: ", "Examine the initializer category and declared type for ci, ri, and rci.");
    kv("Step 2: ", "Deduce the type for plain variables a, b, and c.");
    kv("Step 3: ", "Deduce the type for the reference declarations for d and e.");
    kv("Step 4: ", "const auto& can bind to th temp 42 because its not expected to change.");
    blank();

    stage("Post-State");
    kv("a -> ", "int");
    kv("b -> ", "int");
    kv("c -> ", "int");
    kv("d -> ", "reference to int");
    kv("e -> ", "reference to const int");
    kv("f -> ", "reference to const int");
    blank();

    stage("Compile-Time Checks");
    cout << a << '\x0a';
    cout << b << '\x0a';
    cout << c << '\x0a';
    cout << d << '\x0a';
    cout << e << '\x0a';
    cout << f << '\x0a';

    classify({
        "Well-Defined: auto a = ci; deduces as int",
        "Well-Defined: auto b = ri; deduces as int",
        "Well-Defined: auto c = rci; deduces as int",
        "Well-Defined: auto d& = i; deduces as int&",
        "Well-Defined: auto e& = ci; deduces as const int&",
        "Well-Defined: const auto f& = 42; binds const reference to a temporary int"
    });

    rule({
        "Plain auto drops top-level const and reference-ness.",
        "auto& must bind legally and keep binding constraints.",
        "const auto& can bind to temporaries."
    });
    return 0;
}