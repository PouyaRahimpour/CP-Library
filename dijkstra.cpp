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

void solve(int tc) {
    const ll INF = 1e18+5;
    auto dijkstra = [&](int s) -> vector<ll> {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[s] = 0;
        pq.emplace(dist[s], s);
        while (!pq.empty()) {
            auto [dist_v, v] = pq.top();
            pq.pop();

            if (dist_v != dist[v]) {
                continue;
            }
            for (auto [u, w] : adj[v]) {
                if (dist[v] + c < dist[u]) {
                    dist[u] = dist[v] + c;
                    pq.emplace(dist[u], u);
                }
            }
        }
        return dist;
    };

    vector<ll> dist = dijkstra(0);
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

