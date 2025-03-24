#include<bits/stdc++.h>
using namespace std;

#define dbg(...) cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//#define TIME cerr << endl << "finished in " << clock()*1.0/CLOCKS_PER_SEC << " sec" << endl;


namespace __DEBUG_UTIL__ {
    const string WHITE = "\033[0;m";
    const string RED = "\033[0;31m";
    const string BLUE = "\033[0;34m";
    const string GREEN = "\033[0;32m";

    bool colored_output = true; 
    string white = colored_output ? WHITE : "";
    string outer = colored_output ? RED : "";
    string var_name = colored_output ? BLUE : "";
    string var_value = colored_output ? GREEN : "";

    template <typename T>
    concept is_iterable = requires(T &&x) { begin(x); } && !is_same_v<remove_cvref_t<T>, string>;

    void print(const char *x) { 
        cerr << x; 
    }
    void print(char x) { 
        cerr << "\'" << x << "\'"; 
    }
    void print(bool x) { 
        cerr << (x ? "T" : "F"); 
    }
    void print(string x) { 
        cerr << "\"" << x << "\"";
    }

    void print(vector<bool> &&v) { 
        /* Overloaded this because stl optimizes vector<bool> by using
           _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << "{";
        for (auto &&i : v) {
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        }
        cerr << "}";
    }

    template <typename T>
    void print(T &&x) {
        if constexpr (is_iterable<T>) {
            if (size(x) && is_iterable<decltype(*(begin(x)))>) { 
                /* Iterable inside Iterable */
                int f = 0;
                int w = max(0, (int)log10(size(x) - 1)) + 2;
                cerr << "\n~~~~~\n";
                for (auto &&i : x) {
                    cerr << setw(w) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            }
            else { 
                /* Normal Iterable */
                int f = 0;
                cerr << "{";
                for (auto &&i : x) {
                    cerr << (f++ ? "," : ""), print(i);
                }
                cerr << "}";
            }
        }
        else if constexpr (requires { x.pop(); }) {
            /* Stacks, Queues, Priority Queues */
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); }) {
                while (!temp.empty()) {
                    cerr << (f++ ? "," : ""), print(temp.top()), temp.pop();
                }
            }
            else {
                while (!temp.empty()) {
                    cerr << (f++ ? "," : ""), print(temp.front()), temp.pop();
                }
            }
            cerr << "}";
        }
        else if constexpr (requires { x.first; x.second; }) {
            /* Pair */
            cerr << "(", print(x.first), cerr << ",", print(x.second), cerr << ")";
        }
        else if constexpr (requires { get<0>(x); }) {
            /* Tuple */
            int f = 0;
            cerr << "("; 
            apply([&f](auto... args) {
                ((cerr << (f++ ? "," : ""), print(args)), ...);
                }, x);
            cerr << ")";
        }
        else {
            cerr << x;
        }
    }

    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++) {
            if (names[i] == '(' or names[i] == '<' or names[i] == '{') {
                bracket++;
            }
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}') {
                bracket--;
            }
        }
        cerr << var_name;
        cerr.write(names, i) << outer << " = " << var_value;
        print(head);
        if constexpr (sizeof...(tail)) {
            cerr << outer << " ||", printer(names + i + 1, tail...);
        }
        else {
            cerr << outer << "]\n" << white;
        }
    }
}

#ifdef TESTCASE // this is becuase when working with generators sometimes I need debug but not testcases/solve
void solve(int);
void TC(int tc) {
    cerr << __DEBUG_UTIL__::BLUE << "------- TC " << tc << " -------\n" << __DEBUG_UTIL__::white;
#ifdef TIME
    auto start = std::chrono::high_resolution_clock::now();
#endif
    solve(0);
#ifdef TIME
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    cerr << __DEBUG_UTIL__::BLUE << (double)duration.count()/1000 << " sec\n" << __DEBUG_UTIL__::white;
#endif
    cerr << __DEBUG_UTIL__::BLUE << "--------------------\n" << __DEBUG_UTIL__::white;
}
#endif


/************************************************/
/*
 * version 2
#define fastio()
#define file()
#define nl "\033[0m" << endl
#define cout cerr << "\033[1;32m"
#define dbg(x) cerr << "(" <<__LINE__ << ") " << #x <<": "; cerr << x << endl;
#define LINE cerr << "__________" << endl;
#define TIME cerr << endl << "finished in " << clock()*1.0/CLOCKS_PER_SEC << " sec" << endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// vector
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

// pair
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

// arr
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr) {
  out << '(';
  for (int i = 0; i < N-1; i++) {
    out << arr[i] << ", ";
  }
  return out << arr[N-1] << ')';
}

// deque
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    if (deq.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++) {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

// unordered_map
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// map
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// unordered_set
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// multiset
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// unordered_multiset
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// set
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}
*/



/*
// Source: https://stackoverflow.com/a/31116392/12128483
template<typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}
*/

/************************************************/

// version 1
/*
void _print(const int& t) {cerr << t;} void _print(const ll& t) {cerr << t;} void _print(const char& t) {cerr << t;} void _print(const string& t) {cerr << t;} void _print(const ld& t) {cerr << t;} void _print(const double& t) {cerr << t;}
// pair
template <class T, class V> void _print(const pair<T, V>& p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
// arr
template<class T, size_t N> void _print(array<T, N>& a) { cerr << "{ "; for (int i=0; i<N; i++) { cerr << a[i] << " "; } cerr << "}"; }
// map
template <class T, class V> void _print(const map<T, V>& v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// vector
template <class T> void _print(const vector<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// set
template <class T> void _print(const set<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// multiset
template <class T> void _print(const multiset<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// queue
template <class T> void _print(queue<T>& q) { cerr << "[ "; T x; stack<T> tmp; for (int i=0; i<q.size(); i++) { x = q.front(); q.pop(); tmp.push(x); q.push(x); } while (!tmp.empty()) { x = tmp.top(); tmp.pop(); _print(x); cerr << " "; } cerr << "]"; }
// stack
template <class T> void _print(stack<T>& s) { cerr << "[ "; stack<T> tmp; T x; while (!s.empty()) { x = s.top(); s.pop(); tmp.push(x); } while (!tmp.empty()) { x = tmp.top(); tmp.pop(); _print(x); cerr << " "; s.push(x); } cerr << "]"; }
// deque
template <class T> void _print(deque<T>& dq) { cerr << "[ "; T x; stack<T> tmp; for (int i=0; i<dq.size(); i++) { x = dq.front(); _print(x); cerr << " "; dq.pop_front(); dq.pb(x); } cerr << "]"; }
*/

