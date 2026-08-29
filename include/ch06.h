/*
 * ch06.h
 *
 * Created for C++ Primer 5e Chapter 6: Functions
 *
 * Purpose
 * -------
 * Function exercises and experiments from Chapter 6.
 * Each function is documented with its exercise number and purpose.
 */

#ifndef CPP_PRACTICE_CH06_H
#define CPP_PRACTICE_CH06_H

#include <iostream>
#include <string>
#include <vector>

namespace ch06 {

inline int fact(int n) {
    int res = 1;
    while (n > 1)
        res *= n--;
    return res;
}

} // namespace ch06

#endif // CPP_PRACTICE_CH06_H
