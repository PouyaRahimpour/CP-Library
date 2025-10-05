template<class T, int Dim>
struct Vector {
    array<T, Dim> v{};
    Vector& operator +=(const Vector &a) {
        for (int i=0; i<Dim; i++) {
            v[i] += a.v[i];
        }
        return *this;
    }
    Vector& operator -=(const Vector &a) {
        for (int i=0; i<Dim; i++) {
            v[i] -= a.v[i];
        }
        return *this;
    }
    friend Vector mul(T t, Vector a) {
        for (int i=0; i<Dim; i++) {
            a.v[i] *= t;
        }
        return a;
    }
    friend Vector mul(Vector a, T t) {
        for (int i=0; i<Dim; i++) {
            a.v[i] *= t;
        }
        return a;
    }
    friend T dot(const Vector &a, const Vector& b) {
        T res = 0;
        for (int i=0; i<Dim; i++) {
            res += a.v[i]*b.v[i];
        }
        return res;
    }

    // TODO: implement for 3d
    friend T cross(const Vector &a, const Vector &b) {
        // just return the sign in 2d
        assert(Dim == 2);
        return a.v[0]*b.v[1] - b.v[0]*a.v[1];
    }
    // returns l2 norm squared
    friend T norm2(const Vector &a) {
        T res = 0;
        for (int i=0; i<Dim; i++) {
            res += a.v[i]*a.v[i];
        }
        return res;
    }
    friend Vector operator +(Vector a, const Vector &b) {
        return a += b;
    }
    friend Vector operator -(Vector a, const Vector &b) {
        return a -= b;
    }

    friend ostream& operator<<(ostream &os, const Vector &a) {
        os << "{";
        for (int i=0; i<Dim; i++) {
            os << a.v[i] << ",}"[i==Dim-1];
        }
        return os;
    }
    friend istream& operator >>(istream &is, Vector &a) {
        for (int i=0; i<Dim; i++) {
            is >> a.v[i];
        }
        return is;
    }
};
using V = Vector<ld, 2>;
