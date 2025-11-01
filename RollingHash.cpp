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
#define Solve solve
#endif
#define nl '\n'

template<ll mod>
struct Mint {
    ll x;
    Mint() :x(0) {}
    Mint(ll a) :x((a%mod+mod)%mod) {}
    explicit operator ll() const { return x; }
    explicit operator int() const { return x; }

    Mint& operator+=(const Mint& a) { if ((x += a.x) >= mod) x-=mod; return *this;}
    Mint& operator-=(const Mint& a) { if ((x -= a.x) < 0) x+=mod; return *this;}
    Mint& operator*=(const Mint& a) { if ((x *= a.x) >= mod) x%=mod; return *this;}
    friend Mint mpow(Mint a, ll p) { assert(p >= 0); return p==0?1:mpow(a*a, p/2)*(p&1?a:1); }
    Mint& operator/=(const Mint& a) { if ((x *= (ll)mpow(a, mod-2)) >= mod) x%=mod; return *this;}

    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b;}

    bool operator<(const Mint& a)const { return x < a.x;}
    bool operator==(const Mint& a)const { return x == a.x;}

    friend istream& operator>>(istream& i, Mint& a) { i >> a.x; return i;}
    friend ostream& operator<<(ostream& o, const Mint& a) {o << a.x; return o;}
};
const int mod1 = 1e9+7, mod2 = 998244353;
using mi = Mint<mod1>;
// TODO: implicit conversion from int and ll to mi

template<int p, int N>
struct RollingHash {
    static inline vector<mi> pows, pinv;
    static void init() {
        pows.resize(N);
        pinv.resize(N);
        pows[0] = pinv[0] = 1;
        for (int i=1; i<N; i++) {
            pows[i] = pows[i-1]*p;
        }
        for (int i=1; i<N; i++) {
            pinv[i] = pinv[i-1]/p;
        }
    }

    vector<mi> hash;
    int n;
    RollingHash(string a) {
        n = (int)a.size();
        hash.resize(n+1);
        for (int i=1; i<=(int)a.size(); i++) {
            hash[i] = hash[i-1] + (a[i-1]-'0'+ 1)*pows[i-1];
        }
    }

    // [l, r)
    mi get(int l, int r) {
        return (hash[r] - hash[l]) * pinv[l];
    }
};
const int P = 5, N = 1e6+5;
using Hash = RollingHash<P, N>;


void solve(int tc) {
    string a, b; cin >> a >> b;
    auto H1 = Hash(a);
    auto H2 = Hash(b);
    int n = (int)a.size();
    auto concat = [&] (mi h1, int l1, mi h2) -> mi {
        return h1 + h2*mpow((mi)P, l1);
    };
    mi hb = H2.get(0, n);
    for (int i=0; i<n; i++) {
        if (concat(H1.get(i, n), n-i, H1.get(0, i)) == hb) {
            cout << i << nl;
            return;
        }
    }
    cout << -1 << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Hash::init();

    int t = 1;
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}
