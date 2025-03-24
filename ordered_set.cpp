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

// s.order_of_key(k) -> number of elements less than k 
// *s.find_by_order(index) -> s[index]
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> 
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 


void solve(int tc) {
    // create
    ordered_set<int> s;

    //insert
    s.insert(1);

    // erase
    s.erase(s.find_by_order(s.order_of_key(t)));

    int idx = *s.find_by_order(1);

    s.order_of_key(1);
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


