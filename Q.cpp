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

struct Q {
    ll p, q;

    Q operator+(Q& other) {
        ll t1 = p*other.q + q*other.p;
        ll t2 = q*other.q;
        ll g = gcd(t1, t2);
        assert(t2 != 0);
        return Q{t1/g, t2/g};
    }
    Q operator*(Q& other) {
        ll t1 = p*other.p;
        ll t2 = q*other.q;
        ll g = gcd(t1, t2);
        assert(t2 != 0);
        return Q{t1/g, t2/g};
    }
    Q operator/(Q& other) {
        ll t1 = p*other.q;
        ll t2 = other.p*q;
        ll g = gcd(t1, t2);
        assert(t2 != 0);
        return Q{t1/g, t2/g};
    }
    bool operator==(Q& other) const {
        if (p != other.p || q != other.q) {
            return 0;
        }
        return 1;
    }
    friend ostream& operator<<(ostream& os, const Q& obj) {
        os << '[' << obj.p << ',' << obj.q << ']';
        return os;
    };
};

void solve(int tc) {
    Q q1 = Q{5, 4};
    Q q2 = Q{5, 4};
    Q ans = q1+q2*q1/q1;
    cout << ans << nl;
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
