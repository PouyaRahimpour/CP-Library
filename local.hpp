
#pragma once

#include <chrono>
#include <iostream>

#if defined(GENERATOR) || defined(VALIDATOR) || defined(CHECKER)
#undef TESTCASE
#undef TIME
#include "testlib.h"
#endif

#if defined(DEBUG) || defined(TESTCASE) || defined(TIME)
#include "debug.hpp"
#endif

#ifdef DEBUG
#define dbg(...) \
    std::cerr << debug_util::red << __LINE__ << ": [", \
    debug_util::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif

#if defined(TESTCASE) || defined(TIME)

void solve(int);

inline void Solve(int tc) {
#ifdef TESTCASE
    std::cerr << debug_util::blue
              << "------- TC " << tc << " -------\n"
              << debug_util::white;
#endif

#ifdef TIME
    auto start = std::chrono::steady_clock::now();
#endif

    solve(tc);

#ifdef TIME
    auto stop = std::chrono::steady_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            stop - start
        );

    std::cerr << debug_util::blue
              << static_cast<double>(duration.count()) / 1000
              << " sec\n"
              << debug_util::white;
#endif

#ifdef TESTCASE
    std::cerr << debug_util::blue
              << "--------------------\n"
              << debug_util::white;
#endif
}

#else
#define Solve solve
#endif

