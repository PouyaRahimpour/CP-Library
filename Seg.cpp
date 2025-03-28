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

// V is type of input vector
// T is datatype of tree nodes 
// just implement {make, combine, I}
template<class V, class T>
struct Seg {
	vector<T> t;
	vector<V> a;
	int n;
    T I;
	Seg(const vector<V>& _a, const T& _I) {
		n = (int)_a.size();
        I = _I;
		t.resize(4*n);
		a.resize(n+1);
		copy(_a.begin(), _a.end(), a.begin()+1);
		build(1, 1, n);
	}
	T make(V x) {
        // TODO: Impl
		T res = (T)x;
		return res;
	}
    T combine(const T& x, const T& y) {
        // TODO: Impl
        /* add
         */
        T res = x + y;
        /* min, max
           T res = min(x, y);
         */
        return res;
    }
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = make(a[tl]);
			return;
		}
		int md = (tl+tr)/2;
		build(2*v, tl, md);
		build(2*v+1, md+1, tr);
		t[v] = combine(t[2*v], t[2*v+1]);
	}
    // point update
	void upd(int v, int tl, int tr, int pos, V val) {
		if (tl == tr) {
			t[v] = make(val);
			a[pos] = val;
			return;
		}
		int md = (tl+tr)/2;
		if (pos <= md) {
			upd(2*v, tl, md, pos, val);
		} else {
			upd(2*v+1, md+1, tr, pos, val);
		}
		t[v] = combine(t[2*v], t[2*v+1]);
	}
    // range query
	T qry(int v, int tl, int tr, int l, int r) {
	    if (r < tl || l > tr) {
            return I; // identity of operator
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        int md = (tl+tr)/2;
        return combine(
            qry(2*v, tl, md, l, r),
            qry(2*v+1, md+1, tr, l, r)
            );
	}
};

void solve(int tc) {
    int n = 10;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    // Seg -> upd, qry both O(log n)
    int idx = 5, delta = 3, l = 2, r = 7;
    Seg seg = Seg<int, ll>(v, 0);
    seg.upd(1, 1, n, idx, delta);
    ll ans = seg.qry(1, 1, n, l, r);
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
