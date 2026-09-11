#include <iostream>
#include <string>
#include "report.h"
using namespace rpt;
using std::string, std::cin, std::cout, std::endl;


int main() 
{
    cout << boolalpha;
    header(
            "String Compare Lexicograohy",
            "Determine how std::string works in comparisons when strings differe in length, first differing characters and case"
    );

    inputs({
        "No inputs",
        "Objects involved: { std::string a = \"Hello\", std::string b = \"Hello World\", std::string c = \"Hiya\", std::string d = \"abc\", std::string e = \"abcd\", std::string f = \"abD\", std::string g = \"Zebra\", std::string h = \"apple\" }"
    });
    
    pipeline_begin();
    stage("Pre-State");
    string a = "Hello";
    string b = "Hello World";
    string c = "Hiya";
    string d = "abc";
    string e = "abcd";
    string f = "abD";
    string g = "Zebra";
    string h = "apple";
    blank();

    stage("Comparisons");
    kv("Possible Reading 1: ", "String comparison is mostly about lenght.");
    kv("Possible Reading 2: ", "String comparisond  scan left to right, and the first difference decides unless one ends first.");
    blank();

    stage("Operations");
    kv("Step 1: ", "Evaluate a < b");
    kv("Step 2: ", "Evaluate c > a");
    kv("Step 3: ", "Evaluate d < e");
    kv("Step 4: ", "Evaluate d > f");
    kv("Step 5: ", "Evaluate g < h");
    blank();

    stage("Post-State");
    kv("a < b -> ", a < b); // true
    kv("c > a -> ", c > a); // true
    kv("d < e -> ", d < e); // true
    kv("d > f -> ", d > f); // true
    kv("g < h -> ", g < h); // true
    blank();

    stage("Compile-Time Checks");
    kv("a -> ", "type std::string");
    kv("b -> ", "type std::string");
    kv("c -> ", "type std::string");
    kv("d -> ", "type std::string");
    kv("e -> ", "type std::string");
    kv("f -> ", "type std::string");
    kv("g -> ", "type std::string");

    classify({
        "Well-Defined: a < b results to true.",
        "Well-Defined: c > a results to true.",
        "Well-Defined: d < e results to true.",
        "Well-Defined: d > f results to true.",
        "Well-Defined: g < h results to true.",
       });

    rule({
        "std::string compares lexicgraphically..",
        "compares left to right; the first difference decides; if one ends first when matching, that string is the smaller one.",
        "case-sensitive: uppercase and lowercase have different character values."
    });

    return 0;

}
