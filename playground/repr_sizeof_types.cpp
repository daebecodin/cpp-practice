/*
 * Created by Durand Dyer-Branch on 2/26/26.
 *
*/

#include "report.h"
#include <iostream>
// #include <cstddef>
using namespace rpt;
using namespace std;

int main()
{
    cout << boolalpha;
    header(
        "Represent Sizes of Different Types",
        "View that the sizeOf() method returns the system dependent storage sized for varius types, showing range/precision"
        );
    inputs({
        "No Runtime Inputs"
        });

    pipeline_begin();
    stage(
        "Representation / Range"
        );

    note(
        "Integral / Character Types"
    );
    repr_range<bool>("bool");
    blank();
    repr_range<char>("char");
    blank();
    repr_range<signed char>("signed char");
    blank();
    repr_range<unsigned char>("unsigned char");
    blank();
    repr_range<short>("short");
    blank();
    repr_range<unsigned short>("unsigned short");
    blank();
    repr_range<int>("int");
    blank();
    repr_range<unsigned int>("unsigned int");
    blank();
    repr_range<long>("long");
    blank();
    repr_range<unsigned long>("unsigned long");
    blank();
    repr_range<long long>("long long");
    blank();
    repr_range<unsigned long long>("unsigned long long");
    blank();

    note(
        "Floating-Point Types:"
        );
    repr_range<float>("float");
    blank();
    repr_range<double>("double");
    blank();
    repr_range<long double>("long double");
    blank();

    stage("Promotion");
    note("n/a");
    stage("Compute");
    note("n/a");
    stage("Convert / Assign");
    note("n/a");

    classify({
        "sizeof(T): well-defined (yields a size_t constant expression)",
        "numeric_limits<T> queries: well-defined",
        "Observed sizes/ranges (and whether plain char is signed): implementation-defined (vary by implementation)",
    });

    rule({
        "sizeof(char) will all equal 1 by definition of a byte",
        "Exact sizes of primitive types depends on the users system",
        "Larger storage offers wider integer ranges and more floating precision"
    });

    return 0;
}