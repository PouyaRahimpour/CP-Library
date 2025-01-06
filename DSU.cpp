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

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) {
        n = _n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (x < y) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};

void solve(int tc) {
    int n; cin >> n;
    DSU dsu = DSU(n);
    int root = dsu.find(x);
    bool b = dsu.merge(v, u);
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
