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

struct SCC {
    int _n, c;
    vector<vector<int>> _g, g;
    vector<int> id, topo;

    SCC(vector<vector<int>>& g_) {
        c = 0;
        _g = g_;
        _n = (int)_g.size();
        id.resize(_n, -1);

        make();
        topo_sort();
    }
    void make() {
        vector<vector<int>> g_t(_n);
        for (int u=0; u<_n; u++) {
            for (int v: _g[u]) {
                g_t[v].push_back(u);
            }
        }

        vector<int> ord, vis(_n);
        auto dfs = [&] (auto&& self, int u) -> void {
            vis[u] = 1;
            for (int v: _g[u]) {
                if (!vis[v]) {
                    self(self, v);
                }
            }
            ord.push_back(u);
        };
        for (int u=0; u<_n; u++) {
            if (!vis[u]) {
                dfs(dfs, u);
            }
        }
        reverse(ord.begin(), ord.end());

        auto dfs1 = [&] (auto&& self, int u) -> void {
            id[u] = c-1;
            for (int v: g_t[u]) {
                if (id[v] == -1) {
                    self(self, v);
                } else if (id[v] != id[u]) {
                    assert(id[v] < c);
                    g[id[v]].push_back(id[u]);
                }
            }
        };
        for (int u: ord) {
            if (id[u]==-1) {
                c++;
                g.resize(c);
                dfs1(dfs1, u);
            }
        }
    }

    void topo_sort() {
        vector<int> vis(c);
        auto dfs = [&] (auto&& self, int u) -> void {
            vis[u] = 1;
            for (int v: g[u]) {
                if (!vis[v]) {
                    self(self, v);
                }
            }
            topo.push_back(u);
        };
        for (int u=0; u<c; u++) {
            if (!vis[u]) {
                dfs(dfs, u);
            }
        }
    }
};

void solve(int tc) {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n); // adj graph
    SCC S = SCC(g);
    S.c //-> number of scc's
    S.scc //-> id of scc of each node
    S.g2 //-> condensation graph
    S.topo //-> toposort of condensation graph
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

