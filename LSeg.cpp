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
// just implement {make, combine, merge, apply}
template<class V, class T, class T1>
struct LSeg {
	vector<T> t;
	vector<T1> t1;
    vector<bool> mark;
    T I;
    T1 I1;

	LSeg(const vector<V>& a, const T& _I, const T1& _I1) {
		int n = (int)a.size();
        I = _I;
        I1 = _I1;
		t.resize(4*n);
        t1.resize(4*n, I1);
        mark.resize(4*n);
		build(1, 0, n-1, a);
	}

    // TODO
	inline T make(V x) {
        return (T)x;
	}
    inline T combine(const T& x, const T& y) {
        return x+y;
    }
    inline void merge(T1& x, const T1& y) {
        x.mul = x.mul*y.mul;
        x.add = y.mul*x.add + y.add;
    }
    inline void apply(int v, int tl, int tr) {
        t[v] = t1[v].mul*t[v] + t1[v].add*(tr-tl+1);
    }

    void push(int v, int tl, int tr) {
        apply(v, tl, tr);
        if (tl != tr) {
            merge(t1[2*v], t1[v]);
            merge(t1[2*v+1], t1[v]);
            mark[2*v+1] = mark[2*v] = 1;
        }
        mark[v] = 0;
        t1[v] = I1;
    }

	void build(int v, int tl, int tr, const vector<V>& a) {
		if (tl == tr) {
			t[v] = make(a[tl]);
			return;
		}
		int md = (tl+tr)/2;
		build(2*v, tl, md, a);
		build(2*v+1, md+1, tr, a);
		t[v] = combine(t[2*v], t[2*v+1]);
	}
 
    // range query
	T qry(int v, int tl, int tr, int l, int r) {
        if (mark[v]) push(v, tl, tr);

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

    // range update
    void upd(int v, int tl, int tr, int l, int r, T1 val) {
        if (mark[v]) push(v, tl, tr);

        if (r < tl || l > tr) {
            return;
        }
        if (l <= tl && tr <= r) {
            merge(t1[v], val);
            push(v, tl, tr);
            return;
        }
        int md = (tl+tr)/2;
        upd(2*v, tl, md, l, r, val);
        upd(2*v+1, md+1, tr, l, r, val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
};

void solve(int tc) {
    int n = 10;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    // LSeg -> upd, qry both O(log n)
    int val = 3;
    LSeg lseg = LSeg<int, ll>(v, 0);
    // update might be set or add by delta depending on how you implement "push"
    lseg.upd(1, 1, n, l, r, val);
    ans = lseg.qry(1, 1, n, l, r);
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
