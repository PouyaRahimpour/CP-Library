#define CHECKER
#define DEBUG
#ifdef LOCAL
#include "local.h"
#else
#include "testlib.h"
#define dbg(...)
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define nl endl

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    // inf
    // ouf
    // ans (optional)

    int n = inf.readInt();
    ll val=0, ans_val=0;

    quitf(
        _wa,
        "expected %lld, found %lld",
        ans_val,
        val
    );

    quitf(_ok, "correct");
}

