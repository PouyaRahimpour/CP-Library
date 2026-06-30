// custom controls

#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#define dbg(...) cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

#if defined(GENERATOR) || defined(VALIDATOR)
#undef TESTCASE
#undef TIME
#include "/home/pouya/dev/cp/lib/testlib.h"
#endif

#if defined(TESTCASE) || defined(TIME) 
#ifndef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#endif

void solve(int);

void Solve(int tc) {

#ifdef TESTCASE
    cerr << __DEBUG_UTIL__::BLUE << "------- TC " << tc << " -------\n" << __DEBUG_UTIL__::white;
#endif

#ifdef TIME
    auto start = std::chrono::high_resolution_clock::now();
#endif

    solve(tc);

#ifdef TIME
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    cerr << __DEBUG_UTIL__::BLUE << (double)duration.count()/1000 << " sec\n" << __DEBUG_UTIL__::white;
#endif

#ifdef TESTCASE
    cerr << __DEBUG_UTIL__::BLUE << "--------------------\n" << __DEBUG_UTIL__::white;
#endif

}
#else
#define Solve solve
#endif


