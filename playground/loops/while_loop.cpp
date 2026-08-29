
#include "pch.h"

// Print numbers from start down to 1
void printCountdown(int start) {
    int end{};
    while (start > end) {
        std::cout << start << " ";
        --start;
    }
    std::cout << '\x0a';
}

void printCountUp(int start) {
    int end{5};

    while (start < end) {
        std::cout << start << " ";
        ++start;
    }
    std::cout << '\x0a';
}

void printShape4(int start, int end) {

    int outer{start};

    while (end > start) {
       int inner{end};

        while (inner >= start) {

            if ( inner <= outer ) {


                --inner;
            }
        }
    }



}

int main() {
   // int i{0};
   //  while (i < 5) {
   //      printCountUp(i);
   //      ++i;
   //  }

    int i{1};
    while (i <= 5) {
        printShape4(1,5);
        ++i;
    }
    return 0;
}