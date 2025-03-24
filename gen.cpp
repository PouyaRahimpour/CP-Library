#ifdef LOCAL
#include "/home/pouya/dev/cp/lib/testlib.h"
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#include "testlib.h"
#endif
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define nl endl


int main (int argc, char* argv []) { 
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    cout << rnd.next(n) << nl; // [0, n)
    cout << rnd.next(1, n) << nl; // [1, n]
    cout << rnd.next((double)n) << nl; // real [0, n)
    cout << rnd.next("cat|dog|horse") << nl; // randomly chooses one of cat, dog, horse
    cout << rnd.next("[1-9][0-9]{29}") << nl; // number with 30 digits as string

    vector<int> a({5, 2, 6, 3, 6, 7, 9});
    cout << rnd.any(a) << nl; // works with any container (e.g string, set, ...)
                              
    for (int i=0; i<10; i++) {
        cout << rnd.wnext(n, 3) << ' '; // with 3 more maximum (4 times) of random sample from [0, n) -> more towards the end
    }
    cout << nl;

    shuffle(a.begin(), a.end());
    dbg(a);
}
