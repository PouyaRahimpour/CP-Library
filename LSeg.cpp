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
// just implement {make, combine, push, I}
template<class V, class T>
struct LSeg {
	vector<T> t;
	vector<T> t1;
	vector<V> a;
    vector<bool> mark;
    int n;
    T I;
	LSeg(const vector<V>& _a, const T& _I) {
		n = (int)_a.size();
        I = _I;
		t.resize(4*n);
        t1.resize(4*n);
        mark.resize(4*n);
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
    void push(int v, int tl, int tr) {
        // TODO: impl
        /* add
         */
        t[v] += t1[v]*(tr-tl+1);
        /* min, max
           t[v] += t1[v];
         */

        if (tl != tr) {
            t1[2*v+1] = t1[2*v] = t1[v];
            mark[2*v+1] = mark[2*v] = 1;
        }
        mark[v] = 0;
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
    void upd(int v, int tl, int tr, int l, int r, V val) {
        if (mark[v]) push(v, tl, tr);
        if (r < tl || l > tr) {
            return;
        }
        if (l <= tl && tr <= r) {
            t1[v] = val;
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
