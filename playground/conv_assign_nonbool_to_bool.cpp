/*
 * Created by Durand Dyer-Branch on 2/26/26.
 *
*/

#include "report.h"
#include <iostream>
using namespace rpt;
using namespace std;

int main()
{
    cout << boolalpha;
    header(
        "Assigning a non-bool source  type to a boolean target",
        "Show that assigning an integral value to a bool yields false if 0, otherwise true"
    );

    inputs({
        "Test Inputs: x - value assigned to bool",
        "Suggested: 0, 1, -1, 42",
        "Operation: bool b = x;"
    });

    long long x = 0;
    cout << "Enter x: ";
    cin >> x;

    pipeline_begin();
    stage("Representation / Range");
    repr_range<bool>("boolean");
    repr_range<long long>("long long");
    blank();

    stage("Promote");
    note("This is a direct conversion/assignment to bool (not a usual arithmetic conversion step).");
    blank();

    stage("Compute");
    note("No arithmetic operations are performed; we only convert/assign");
    blank();

    stage("Convert / Assign");
    bool b = x;
    kv("x = ", x);
    kv("b (printed as bool) = ", b);
    kv("b (as int) = ", static_cast<int>(b));
    blank();

    classify({
        "Integral -> Bool: well-defined",
        "Rule used: if x == 0 -> false; otherwise true"
    });

    rule({
        "Assigning an integral to a bool yields false if the value is 0",
        "Assigning any non-zero value to a bool yields true"
    });
    return 0;

}