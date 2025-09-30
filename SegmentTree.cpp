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

// credit: jiangly's implementation
template<class Monoid>
struct SegmentTree {
    int n;
	vector<Monoid> info;

	SegmentTree(const vector<Monoid>& a) : n((int)a.size()) {
		info.resize(4<<__lg(n), Monoid());
        function<void(int, int, int)> build = [&] (int p, int l, int r) {
            if (r - l == 1) {
                info[p] = a[l];
                return;
            }
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m, r);
            pull(p);
        };
		build(1, 0, n);
	}

    void pull(int p) {
        info[p] = info[2*p] + info[2*p+1];
    }
 
	Monoid rangeQry(int p, int l, int r, int L, int R) {
        if (r <= L || l >= R) {
            return Monoid();
        }
        if (L <= l && r <= R) {
            return info[p];
        }
        int m = (l+r)/2;
        return rangeQry(2*p, l, m, L, R) + rangeQry(2*p+1, m, r, L, R);
    }
    Monoid rangeQry(int L, int R) {
        return rangeQry(1, 0, n, L, R);
    }

    void modify(int p, int l, int r, int pos, const Monoid &val) {
        if (r-l == 1) {
            info[p] = val;
            return;
        }
        int m = (l+r)/2;
        if (pos < m) {
            modify(2*p, l, m, pos, val);
        } else {
            modify(2*p+1, m, r, pos, val);
        }
        pull(p);
    }
    void modify(int pos, const Monoid &val) {
        modify(1, 0, n, pos, val);
    }
};

// implement {Info} with identity of operations as defualt objects.
struct Info {
    int sum;
    int cnt;
    Info(int x=0, int y=1) {
        sum = x, cnt = y;
    }
    Info& operator +=(const Info &a) {
        sum += a.sum;
        cnt += a.cnt;
        return *this;
    }
    friend Info operator +(Info a, const Info &b) { return a += b; }
};


void solve(int tc) {
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

