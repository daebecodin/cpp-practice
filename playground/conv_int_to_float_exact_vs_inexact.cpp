/*
 *  Created by Durand Dyer-Branch on 2/27/26.
*/

#include <iostream>
#include "report.h"
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
using namespace rpt;

int main()
{
    header(
        "Convert an int to a float",
        "Demonstrate that int -> float becomes inexact once integers exceed floats precision; different ints can convert back to the same float, "
        "so converting back can change the value"
        );

    inputs({
        "Default x: {16777216, 16777217}",
        "User-Defined x: different magnitude of numbers"
    });

    cout << "Would you like to try default values? (y/n): ";
    string answer;
    if (!(cin >> answer)) {
        note("Input error detected. Plz enter a valid floating-point value");
        return 1;
    }

    int x{};
    if (answer == "y" || answer == "Y") {
        cout << "Do you want to test\x0a 1. 16777216\x0a 2. 16777217\x0a";
        cout << "Enter 1 or 2\x0a";
        int choice;
        if (!(cin >> choice)) {
            note("Input error detected. Plz enter a valid floating-point value");
            return 1;
        }
        x = (choice == 2) ? 16777217 : 16777216;
    } else {
       cout << "Enter a value for x: ";
        if (!(cin >> x)) {
            note("Input error detected. Plz enter a valid int value");
            return 1;
        }
    }

    pipeline_begin();
    stage("Representation / Range");
    repr_range<float>("float");
    blank();
    repr_range<int>("int");
    blank();

    stage("Promotion");
    note("(n/a)");

    stage("Compute");
    note("(n/a)");

    stage("Convert / Assign");
    float f = static_cast<float>(x);
    int back = static_cast<int>(f);
    cout << setprecision(numeric_limits<float>::max_digits10);

    kv("int x = ", x);
    kv("float f = x -> ", f);
    kv("int back = f ->", back);
    blank();

    classify({
        "int -> float: defined; Representation may be inexact when x exceeds float integer precision (2^24)",
        "float -> int: defined only if the value is representable in int range"
    });
    rule({
        "Floats typically have 24 bits of precision; Beyond that, not every int is representable ",
        "So x and x+1 can convert to the same float; converting back to int can change the value."

    });

    return 0;
}