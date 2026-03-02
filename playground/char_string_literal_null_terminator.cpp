/*
 * Created by Durand Dyer-Branch on 2/28/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main() {

    char c = 'a';
    const char s1[] = "a";
    const char* s2 = "a";


    header(
        "Char, String, Literal, Null Terminator",
        "Demonstrates the difference between character literal and string literal, including the implicit '\\0' "
        "terminator on string literals and how that shows up in sizeof and indexing"
    );

    inputs({
        "No input",
        "Fixed values: c='a', s1[]=\"a\", s2=\"a\""
});

    pipeline_begin();
    stage("Representation / Ramge");
    repr_range<char>("char");
    blank();
    repr_range<unsigned char>("unsigned char");
    blank();
    kv("sizeof(const char*) -> ", sizeof(const char*));

    kv("sizeof c -> ", sizeof(c));
    kv("sizeof \"a\" -> ", sizeof("a"));
    kv("sizeof s1 -> ", sizeof(s1));
    kv("sizeof s2 -> ", sizeof(s2));
    blank();


    stage("Promotion");
    note("(n/a)");

    stage("Compute");
    note("(n/a)");

    stage("Convert / Assign");
    cout << boolalpha;
    kv("c as a char -> ", c);
    kv("numeric code of c -> ", static_cast<int>(static_cast<unsigned char>(c)));
    kv("s1 -> ", s1);
    kv("s2 as address -> ", static_cast<const void*>(s2));
    kv("s2 -> ", s2);
    kv("s1[0] numeric code -> ", static_cast<int>(static_cast<unsigned char>(s1[0])));
    kv("s1[1] numeric code -> ", static_cast<int>(static_cast<unsigned char>(s1[1])));
    kv("s1[1] == \\0 -> ",(s1[1] == '\0'));

    classify({
        "",
        ""
    });

    rule({
        "A string literal is an array of characters {a,..., \\0}, so its size is the sum of all bytes",
        "A character literal is a single character \'a\', so its size is 1 byte",
        "A pointer is an address, sizeof a pointer variable is the pointer size, not the string length"
    });

    return 0;
}