/*
 * Created by Durand Dyer-Branch on 2/28/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "Truthi Values of int inside of if condition",
        "Demonstrate that when used as a condition, numeric values such as int will be recognized at boolean values."
    );

    inputs({
        "Default x values: {0, 1, -1}"
    });

    pipeline_begin();
    stage("Representation");
    repr_range<bool>("bool");
    blank();
    repr_range<int>("int");
    blank();

    stage("Promotion");
    note("(n/a) no mixed-type expression/conversions");

    stage("Compute");
    note("(n/a) no arithmetic to follow; program is control-flow & condition checks");

    stage("Convert / Assign");
    cout << boolalpha << "Enter a value for x: ";
    int x{};
    if (!(cin >> x)) {
        note("Input validation error.");
        return 1;
    }

    bool cond = static_cast<bool>(x);
    kv("x -> ", x);
    kv("cond = bool(x) -> ", cond);
    if (x) {
        note("branch the condition is true");
    } else {
        note("branch if the condition is false");
    }

    classify({
        "int used as condition -> converted to bool: well defined",
        "0 -> false; nonzero -> true"
    });

    rule({
        "As a condition, numeric variables will contextually converted to bool.",
        "0 becomes false; any nonzero values become true"
    });
    return 0;
}