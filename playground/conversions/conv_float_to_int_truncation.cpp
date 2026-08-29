/*
 * Created by Durand Dyer-Branch on 2/27/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
      "Conversion from Floating-Point -> Integer",
      "Demonstrate that conversion from floating-point -> integral yields truncation and rounding towards 0"
    );

    inputs({
        "User-defined value for x",
        "Suggested values: {3.7, 3.0, -3.7, 0.9}"
    });

    cout << "Enter a +/- floating-point value: ";
    double d = getInput("Enter another gloating-point value");


    pipeline_begin();
    stage("Representation / Range");
    repr_range<double>("double");
    blank();
    repr_range<int>("int");
    blank();

    stage("Promotion");
    note("(n/a)");

    stage("Compute");
    note("(n/a)");

    stage("Convert / Assign");
    int i = d;

    kv("double d = ", d);
    kv("int i = d -> ", i);
    blank();

    classify({
        "double -> int: well-defined if the value is representable inside of int",
        "Fractional part is discarded (truncation toward 0)",
    });

    rule({
        "Integrals cannot hold floating values; floating -> int conversion truncates the fractional part (truncation toward 0).",
        "Precondition: the value must be representable in the target int type."
    });

    return 0;
}