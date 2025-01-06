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

vector<string> split(string& s, string delim=" ") {
    set<char> delims;
    vector<string> res;
    for (char c: delim) {
        delims.insert(c);
    }
    string t = "";
    for (int i=0; i<s.size(); i++) {
        if (delims.count(s[i])) {
            res.push_back(t);
            t = "";
        } else {
            t += s[i];
        }
    }
    if (t != "") {
        res.push_back(t);
    }
    return res;
}


void solve(int tc) {
    string a; cin >> a;
    vector<string> res = split(a, ",. ");
    dbg(res);
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

