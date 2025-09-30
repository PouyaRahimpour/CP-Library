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
template<class Monoid, class Monoid1>
struct LazySegmentTree {
    int n;
	vector<Monoid> info;
	vector<Monoid1> tag;

	LazySegmentTree(const vector<Monoid>& a) : n((int)a.size()) {
		info.resize(4<<__lg(n), Monoid());
        tag.resize(4<<__lg(n), Monoid1());
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
    void apply(int p, const Monoid1 &val) {
        info[p].apply(val);
        tag[p] += val;
    }

    void push(int p) {
        apply(2*p, tag[p]);
        apply(2*p+1, tag[p]);
        tag[p] = Monoid1();
    }
 
	Monoid rangeQry(int p, int l, int r, int L, int R) {
        if (r <= L || l >= R) {
            return Monoid();
        }
        if (L <= l && r <= R) {
            return info[p];
        }
        int m = (l+r)/2;
        push(p);
        return rangeQry(2*p, l, m, L, R) + rangeQry(2*p+1, m, r, L, R);
    }
    Monoid rangeQry(int L, int R) {
        return rangeQry(1, 0, n, L, R);
    }

    void rangeApply(int p, int l, int r, int L, int R, const Monoid1 &val) {
        if (r <= L || l >= R) {
            return;
        }
        if (L <= l && r <= R) {
            apply(p, val);
            return;
        }
        int m = (l+r)/2;

        push(p);
        rangeApply(2*p, l, m, L, R, val);
        rangeApply(2*p+1, m, r, L, R, val);
        pull(p);
    }
    void rangeApply(int L, int R, const Monoid1 &val) {
        rangeApply(1, 0, n, L, R, val);
    }

    void modify(int p, int l, int r, int pos, const Monoid &val) {
        if (r-l == 1) {
            info[p] = val;
            return;
        }
        int m = (l+r)/2;
        push(p);
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

// implement {Tag, Info} with identity of operations as defualt objects.
struct Tag {
    int add, mul;
    Tag(int x = 0, int y = 1) {
        add = x, mul = y;
    }
    Tag& operator +=(const Tag &a) {
        mul = mul*a.mul;
        add = add*a.mul+a.add;
        return *this;
    }
    friend Tag operator+(Tag a, const Tag& b) { return a += b; }
};
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
    void apply(const Tag& a) {
        sum = sum*a.mul + a.add*cnt;
    };
    friend Info operator +(Info a, const Info &b) { return a += b; }
};


void solve(int tc) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    LazySegmentTree tree = LazySegmentTree<Info, Tag>(vector<Info>(n));
    for (int i=0; i<n; i++) {
        tree.modify(i, Info(a[i]));
    }
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, b, c; cin >> l >> r >> b >> c;
            tree.rangeApply(l, r, Tag(c, b));
        } else {
            int l, r; cin >> l >> r;
            cout << tree.rangeQry(l, r).sum << nl;
        }
    }
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

