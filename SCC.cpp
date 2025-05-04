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
    int n, c = 0, timer = 0;
    vector<vector<int>> g, g1, g2;
    vector<int> tin, tout;
    vector<int> scc;
    vector<int> topo;

    SCC(vector<vector<int>>& _g) {
        n = (int)_g.size();
        g = _g;
        g1.resize(n);
        g2.resize(n);
        tin.resize(n);
        tout.resize(n);
        scc.resize(n, -1);

        make();
        topo_sort();
    }
    void make() {
        auto dfs = [&] (auto&& self, int u) -> void {
            tin[u] = timer++;
            for (int v: g[u]) {
                if (!tin[v]) {
                    self(self, v);
                }
            }
            tout[u] = timer++;
        };
        auto dfs1 = [&] (auto&& self, int u) -> void {
            scc[u] = c;
            for (int v: g1[u]) {
                if (scc[v] == -1) {
                    self(self, v);
                } else if (scc[v] != scc[u]) {
                    g2[scc[v]].push_back(scc[u]);
                }
            }
        };

        for (int i=0; i<n; i++) {
            if (!tin[i]) {
                dfs(dfs, i);
            }
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (int i, int j) {
                return tout[i] > tout[j];
                });

        for (int u=0; u<n; u++) {
            for (int v: g[u]) {
                g1[v].push_back(u);
            }
        }
        for (int i=0; i<n; i++) {
            if (scc[ord[i]]==-1) {
                dfs1(dfs1, ord[i]);
                c++;
            }
        }
        for (int i=0; i<c; i++) {
            sort(g2[i].begin(), g2[i].end());
            g2[i].erase(unique(g2[i].begin(), g2[i].end()), g2[i].end());
        }
    }

    void topo_sort() {
        vector<int> vis(c);
        auto dfs = [&] (auto&& self, int u) -> void {
            vis[u] = 1;
            for (int v: g2[u]) {
                if (!vis[v]) {
                    self(self, v);
                } else if (vis[v] == 1) {
                    // not a DAG, so SCC is wrong
                    dbg("DAG is not DAG");
                    assert(0);
                }
            }
            vis[u] = 2;
            topo.push_back(u);
        };
        for (int i=0; i<c; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
            }
        }
        reverse(topo.begin(), topo.end());
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

