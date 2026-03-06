/*
 * Created by Durand Dyer-Branch on 2/26/26.
 *
 * - Show that all char, signed char, and unsigned char are individual types.
 * - Show that plain char's signedness is implementation-defined
*/


#include <iostream>
#include "report.h"
#include <type_traits>
using namespace std;
using namespace rpt;


int main() {
    cout << boolalpha;

    header(
        "Representing Individual char Types",
        "Show that all char types are distinct and signedness"
        );
    inputs({
        "No Runtime Inputs: inspecting type relation with std::is_same",
        "Types: char, signed char, unsigned char"
    });

    pipeline_begin();
    stage("Representation / Range");
    repr_range<char>("char");
    blank();
    repr_range<signed char>("signed char");
    blank();
    repr_range<unsigned char>("unsigned char");
    blank();

    kv("Plain char is signed = " , numeric_limits<char>::is_signed);
    blank();

    stage("Promote - (n/a)");
    stage("Compute - (n/a)");
    stage("Convert / Assign - (n/a)");
    blank();

    note("Type Identity Checks using std::is_same");
    kv("char == signed char = ", is_same_v<char, signed char>);
    kv("char == unsigned char = ", is_same_v<char, unsigned char>);
    kv("signed char == unsigned char = ", is_same_v<signed char, unsigned char>);

    classify({
        "std::is_same_v comparison: well-defined",
        "Whether plain char is signed: implementation-defined"
    });
    rule({
        "All char types are their own individual types",
        "Plain char may behave as signed or unsigned depending on implementation"
    });

    return 0;
}