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
    return 0;

}
