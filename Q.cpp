struct Q {
    ll a, b;
    // a/b
    Q(ll _a, ll _b): a(_a), b(_b) {
        make();
    }
    Q(ll _a): a(_a), b(1) {}

    void make() {
        assert(b != 0);
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        if (b < 0) {
            a *= -1;
            b *= -1;
        }
    }
    Q operator +(const Q& other) const {
        return Q{a * other.b + b * other.a, b * other.b};
    }
    Q operator -(const Q& other) const {
        return Q{a * other.b - b * other.a, b * other.b};
    }
    Q operator *(const Q& other) const {
        return Q{a * other.a , b * other.b};
    }
    Q inv() const {
        return Q{b, a};
    }
    Q operator /(const Q& other) const {
        return *this * other.inv();
    }

    void operator +=(const Q& other) {
        *this = *this + other;
    }
    void operator -=(const Q& other) {
        *this = *this - other;
    }
    void operator *=(const Q& other) {
        *this = *this * other;
    }
    void operator /=(const Q& other) {
        *this = *this / other;
    }

    bool operator <=(const Q& other) const {
        return a*other.b <= other.a*b;
    }
    bool operator >=(const Q& other) const {
        return  other.a*b <= a*other.b;
    }
    bool operator ==(const Q& other) const {
        return *this <= other && *this >= other;
    }
    bool operator !=(const Q& other) const {
        return !(*this == other);
    }
    bool operator <(const Q& other) const {
        return *this <= other && *this != other;
    }
    bool operator >(const Q& other) const {
        return *this >= other && *this != other;
    }

    friend string to_string(const Q& x) {
        return to_string(x.a) + (x.b != 1 ? "/" + to_string(x.b): "");
    }
    friend ostream& operator <<(ostream& o, const Q& x) {
        return o << to_string(x);
    }
};
