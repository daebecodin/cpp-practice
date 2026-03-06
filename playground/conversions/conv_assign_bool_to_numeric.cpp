/*
* Created by Durand Dyer-Branch on 2/26/26.
*/

#include "report.h"
#include <iostream>
using namespace std;
using namespace rpt;

int main()
{
    cin >> boolalpha;
    cout << boolalpha;
    header("Assigning a boolean to a numeric ",
           "Show that assigning a numeric value to a bool will yield 0 for false and 1 for true."
           );

    inputs({
        "User defined input b - value assigned to numeric type",
        "Suggest Tests: {false, true}"
    });

    cout << "Enter your bool value (true / false): ";
    bool b{};
    if (!(cin >> b)) {
        note("Input error: expected 'true' or 'false'.");
        return 1;
    }

    pipeline_begin();
    stage("Representation / Range");
    repr_range<bool>("boolean");
    blank();
    repr_range<int>("int");
    blank();
    repr_range<double>("double");
    blank();

    stage("Promotion");
    note("This is a direct conversion/assignment; bool -> numeric (not a usual arithmetic conversion step).");

    stage("Compute");
    note("No arithmetic operations are performed; we only convert/assign");
    blank();

    stage("Convert / Assign");
    int i = b;
    double d = b;

    kv("bool b = ", b);
    kv("int i = b -> ", i);
    kv("double d = b -> ", d);
    blank();

    classify({
        "bool -> numeric: well-defined",
        "false converts to 0; true converts to 1"
    });

    rule({
        "Converting a bool to a numeric type yields 0 if false and 1 if true",
        "The target numeric type (int, double, etc) changes the representation format, not the bool value (0, 1)",
    });
}