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
    // write a validator using problem statement
    registerValidation(argc, argv);
    
    ensuref(cond, "", );
    ensure(cond);
    
    int n = inf.readInt(L, R, "n"); // all arguments are optional
    vector<int> ns = inf.readInts(n, L, R); // n space seperated integers
    
    long long t = inf.readLong(L, R, "t");
    vector<long long> ts = inf.readLongs(L, R);
    
    char c = inf.readChar(); // no other option available
    
    double x = inf.readDouble(L, R); // all arguments are optional
    double x = inf.readStrictDouble(L, R, min_precision, max_precision); // all arguments are optional
   
	  string word = inf.readToken(regex); // optional regex string as argument same as readWord()
    
    string s = inf.readString(regex); // optional regex string as argument reads after endl, same as inf.readLine()
    
    inf.readSpace();
    inf.readEoln();
    inf.readEof();

    inf.readEof();
}

