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

template<class V, class T>
struct Seg {
	vector<T> t;
	vector<V> a;
	int n;
	Seg(vector<V>& _a) {
		n = _a.size();
		t.resize(4*n);
		a.resize(n+1);
		copy(_a.begin(), _a.end(), a.begin()+1);
		build(1, 1, n);
	}
	T make(V x) {
        // Impl
		T res = (T)x;
		return res;
	}
    T combine(T& x, T& y) {
        // Impl
        T res = (T)x + (T)y;
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
		if (l <= tl && tr <= r) {
			return t[v];
		}
		int md = (tl+tr)/2;
		if (r <= md) {
			return qry(2*v, tl, md, l, r);
		} else if (l > md) {
			return qry(2*v+1, md+1, tr, l, r);
		} else {
			auto left = qry(2*v, tl, md, l, md);
			auto right = qry(2*v+1, md+1, tr, md, r);
			return combine(left, right);
		}
	}
};


void solve(int tc) {
    vector<int> v;
    int n = v.size();
    Seg seg = Seg<int, ll>(v);
    seg.upd(1, 1, n, idx, delta);
    int ans = seg.qry(1, 1, n, lidx, ridx);
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
