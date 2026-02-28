/*
 * Created by Durand Dyer-Branch on 2/27/26.
*/

#include <iostream>
#include <limits>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "Negative to Unsigned Modulo",
        "Demonstrate unsigned wraparound when assigning a neg value to an unsigned int"
        );

    inputs({
        "int x",
        "Suggested: {-1, -2}"
    });

    cout << "Please enter an Integer value for x: ";
    int x{};
    if (!(cin >> x)) {
        note("Input error detected. Please enter a valid integer");
        return 1;
    }

    pipeline_begin();
    stage("Representation / Range");
    blank();
    repr_range<int>("int");
    blank();
    repr_range<unsigned int>("unsigned int");
    blank();

    stage("Promotion");
    note("(n/a)");

    stage("Compute");
    note("(n/a)");

    stage("Convert / Assign");
    unsigned int u = x;

    kv("int x = ", x);
    kv("unsigned int u = x -> ", u);
    kv("UINT_MAX = ", numeric_limits<unsigned int>::max());

    classify({
        "int -> unsigned: well-defined (reduced by mod 2^n)",
        ""
    });

    rule({
        "Signed -> unsigned is defined: result is x mod 2^n (n being # of bits in unsigned type)",
        "-1 -> UINT_Max, -2 -> UINT_MAX -1, etc"
    });

    return 0;
}