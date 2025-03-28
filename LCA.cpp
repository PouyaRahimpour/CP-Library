#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'


struct LCA {
    int n, LG;
    vector<vector<int>> g, a;
    vector<int> d;
    LCA(int _n, vector<vector<int>> _g) : n(_n), g(_g) {
        LG = 31-__builtin_clz(n)+5;
        a.resize(LG, vector<int>(n));
        d.resize(n);
        auto dfs = [&] (auto&& self, int u, int p=-1) -> void {
            for (int v: g[u]) {
                if (v == p) continue;
                d[v] = d[u]+1;
                a[0][v] = u;
                self(self, v, u);
            }
        };
        dfs(dfs, 0);
        a[0][0] = -1;
        for (int i=1; i<LG; i++) {
            for (int j=0; j<n; j++) {
                int t = a[i-1][j];
                if (t != -1) {
                    a[i][j] = a[i-1][t];
                } else {
                    a[i][j] = -1;
                }
            }
        }
    };
    int get(int x, int y) {
        if (d[x] < d[y]) swap(x, y);
        for (int i=d[x]-d[y], j=0; i>0; i>>=1, j++) {
            if (i&1) {
                x = a[j][x];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i=LG-1; i>=0; i--) {
            if (a[i][x] != a[i][y]) {
                x = a[i][x];
                y = a[i][y];
            }
        }
        return a[0][x];
    }
};

void solve(int tc) {
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LCA T = LCA(n, g);
    while (q--) {
        int x, y; cin >> x >> y; x--, y--;
        cout << T.get(x, y)+1 << nl; // lca of x and y
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

