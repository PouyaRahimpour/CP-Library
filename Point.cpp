#include<bits/stdc++.h>
#ifdef DEBUG
#include "lib/debug.cpp"
#endif
using namespace std;
using ll = long long;

template<class T, int N>
struct Point {
    array<T, N> p{};
    Point(initializer_list<T> v) {
        copy(v.begin(), v.end(), p.begin());
    }
    T& operator[](int i) {
        assert(i<N);
        return p[i];
    }
    const T& operator[](int i) const {
        assert(i<N);
        return p[i];
    }
    Point operator +(const Point& other) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] += other[i];
        }
        return ret;
    }
    Point operator -(const Point& other) const {
        return *this + -1*other;
    }
    Point operator *(const T& scaler) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] *= scaler;
        }
        return ret;
    }
    friend Point operator *(const T& scaler, const Point& q) {
        return q*scaler;
    }
    Point operator /(const T& scaler) const {
        Point ret = *this;
        for (int i=0; i<N; i++) {
            ret[i] /= scaler;
        }
        return ret;
    }
    friend Point operator /(const T& scaler, const Point& q) {
        return q/scaler;
    }

    friend T dot(const Point& a, const Point &b) {
        T ret = 0;
        for (int i=0; i<N; i++) {
            ret += a[i]*b[i];
        }
        return ret;
    }
    // returns norm^2
    friend T norm2(const Point& q) {
        return dot(q, q);
    }
    friend Point cross(const Point& a, const Point& b) {
        assert(N == 3);
        return Point({
            a[1]*b[2]-a[2]*b[1],
            a[2]*b[0]-a[0]*b[2],
            a[0]*b[1]-a[1]*b[0]
        });
    }
    // returns sign of cross product for 2D vectors
    friend T scross(const Point& a, const Point& b) {
        assert(N == 2);
        T ret = a[0]*b[1] - a[1]*b[0];
        if (ret < 0) {
            return -1;
        } else if (ret > 0) {
            return 1;
        } else {
            return 0;
        }
    }

    void operator +=(const Point& other) {
        *this = *this + other;
    }
    void operator -=(const Point& other) {
        *this = *this - other;
    }
    void operator *=(const T& scaler) {
        *this = *this * scaler;
    }

    friend ostream& operator<<(ostream& os, const Point& q) {
        os << "(";
        for (int i=0; i<N; i++) {
            os << q[i] << ",)"[i==N-1];
        }
        return os;
    }
    friend istream& operator >>(istream& is, Point& q) {
        for (int i=0; i<N; i++) {
            is >> q[i];
        }
        return is;
    }
};
// use ll or ld for safety
using P = Point<ll, 2>;

int32_t main() {
    Point<int, 2> p1{1, 2};
    Point<int, 2> p2{0, 1};
    dbg(p1, p2, dot(p1, p2), scross(p1, p2), scross(p2, p1), norm2(p1), 3*p1+p2);

    Point<int, 3> p3{1, 2, 3};
    Point<int, 3> p4{0, 1, 1};
    dbg(p3, p4, cross(p3, p4));
    return 0;
}
