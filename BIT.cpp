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

template<class T>
struct BIT {
    vector<T> t;
    int n;
    BIT(int _n) {
        n = _n+1;
        t.resize(n+1);
    }
    T qry(int idx) {
        assert(idx >= 0); 
        T res = 0;
        while (idx) {
            res += t[idx];
            idx -= idx&-idx;
        }
        return res;
    }
    void add(int idx, int delta) {
        assert(idx>0);
        while (idx<=n) {
            t[idx] += delta;
            idx += idx&-idx;
        }
    }
};

void solve(int tc) {
    int n; cin >> n;
    BIT bit = BIT<ll>(n);
    bit.add(idx, delta);
    int ans = bit.qry(ridx)-bit.qry(lidx);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

