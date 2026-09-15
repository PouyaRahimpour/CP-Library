#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#ifdef LOCAL
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'
/*
beg
mint
bpow
Floor
Ceil
seg
bit
*/
// TODO Lazy Seg
struct LSeg {
    int t[4*N], tt[4*N];
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[l];
            return;
        }
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = t[2*v]+t[2*v+1];
    }
    void relax(int v, int tl, int tr) {
        int delta = tt[v];
        if (delta) {
            if (tl == tr){
                t[v] += delta;
            } else {
                tt[2*v] += delta;
                tt[2*v+1] += delta;
            }
            tt[v] = 0;
        }
    }
    int qry(int v, int tl, int tr, int l, int r) {
        relax(v, tl, tr);
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl+tr)/2;
        if (r <= tm) {
            return qry(2*v, tl, tm, l, r);
        } else if (tm < l) {
            return qry(2*v+1, tm+1, tr, l, r);
        } else {
            return qry(2*v, tl, tm, l, tm) + qry(2*v+1, tm+1, tr, tm+1, r);
        }
    }
    void upd(int v, int tl, int tr, int l, int r, int delta) {
        if (tl == l && tr == r) {
            tt[v] += delta;
            return;
        }
        int tm = (tl+tr)/2;
        if (r <= tm) {
            upd(2*v, tl, tm, l, r, delta);
        } else if (tm < l) {
            upd(2*v+1, tm+1, tr, l, r, delta);
        } else {
            upd(2*v, tl, tm, l, tm, delta);
            upd(2*v+1, tm+1, tr, tm+1, r, delta);
        }
    }
};


void solve(int tc) {
    int n; cin >> n;
    cout << n << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

