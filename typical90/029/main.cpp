#ifdef __TEMPLATE__
#pragma region template
#endif

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

// おまじない
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define OVERLOAD_MACRO(_1, _2, _3, name, ...) name
// loop [begin,end)
#define REP0(end) for (auto _ = decay_t<decltype(end)>{}; (_) != (end); ++(_))
#define REP1(i, end) for (auto i = decay_t<decltype(end)>{}; (i) != (end); ++(i))
#define REP2(i, begin, end) for (auto i = decay_t<decltype(end)>{begin}; (i) != (end); ++(i))
#define rep(...) OVERLOAD_MACRO(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)
// reveres loop [rend,rbegin)
#define RREP1(i, rbegin) for (auto i = (rbegin-1); i >= 0; i--)
#define RREP2(i, rbigin, rend) for (auto i = decay_t<decltype(rbigin)>{rend-1}; (i) >= (rbegin); i--)
#define rrep(...) OVERLOAD_MACRO(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
// is in [l,r)
#define INRANGE1(x, r) (0 <= x && x < r)
#define INRANGE2(x, l, r) (l <= x && x < r)
#define ir(...) OVERLOAD_MACRO(__VA_ARGS__, INRANGE2, INRANGE1)(__VA_ARGS__)

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define yes cout << "yes" << el
#define no cout << "no" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define YESNO(bool) if(bool) { cout<<"YES"<<el; } else { cout<<"NO"<<el; }
#define yesno(bool) if(bool) { cout<<"yes"<<el; } else { cout<<"no"<<el; }
#define YesNo(bool) if(bool) { cout<<"Yes"<<el; } else { cout<<"No"<<el; }
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps)
#define isNum(s) all_of(all(s), [](char c){ return isdigit(c); })
#define debug(x) cerr << #x << " = " << x << el

constexpr int inf = 1073741823;
constexpr ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

// 4近傍、(一般的に)上右下左
constexpr int dy[4] = {-1,0,1,0};
constexpr int dx[4] = {0,1,0,-1};

// 8方向 左上, 上, 右上, 右, 右下, 下, 左下, 左
constexpr int dy8[8] = {-1,-1,-1,0,1,1,1,0};
constexpr int dx8[8] = {-1,0,1,1,1,0,-1,-1};

/***************************************
 mkvec<type>(n or {n1,n2,...}[, init])
****************************************/
template<class T>
inline auto mkvec(const int d, const T& init = T{}) noexcept {
    return vector<T>(d, init);
}
template<class T, size_t n, size_t idx = 0>
auto mkvec(const int (&d)[n], const T& init = T{}) noexcept {
    if constexpr (idx < n - 1) return vector(d[idx], mkvec<T, n, idx + 1>(d, init));
    else return mkvec<T>(d[idx], init);
}

/***************************************
 pairとvectorを簡単に出力できるようにした
****************************************/
template<class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1,T2> p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> v) {
    if constexpr (is_same_v<T, string>) {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << (i+1!=(int)v.size() ? "\n" : "");
        }
    } else {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << (i+1!=(int)v.size() ? spa : "");
        }
    }
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? "\n" : "");
    }
    return os;
}

/***************
 複数の標準入力
****************/
template <class T>
inline void input_cin(T& val) {
    cin >> val;
}
template <class First, class... Rest>
void input_cin(First& first, Rest&... rest) {
    cin >> first;
    input_cin(rest...); // recursive call using pack expansion syntax
}
#define inputi(...) int __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputll(...) ll __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputs(...) string __VA_ARGS__; input_cin(__VA_ARGS__);
template <class T>
inline auto inputv(const int d) {
    vector<T> vec(d);
    for (int i = 0; i < d; i++) {
        cin >> vec[i];
    }
    return vec;
}
template<class T, size_t n, size_t idx = 0>
auto inputv(const int (&d)[n]) noexcept {
    if constexpr (idx < n - 1) {
        int d_make[n - idx];
        copy(begin(d) + idx, end(d), begin(d_make));
        auto vec = mkvec<T>(d_make);
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = inputv<T, n, idx + 1>(d);
        }
        return vec;
    } else {
        return inputv<T>(d[idx]);
    }
}

/*************************
 Pythonのprintみたいなやつ
**************************/
inline void print() {
    cout << el;
}
template <class T>
inline void print(const T& t) {
    cout << t << el;
}
template <class First, class... Rest>
void print(const First& first, const Rest&... rest) {
    cout << first << " ";
    print(rest...); // recursive call using pack expansion syntax
}

/*************************
 値が大きい、小さい方を代入
**************************/
template<class T1, class T2>
inline bool chmax(T1 &a, const T2 b) noexcept {
    bool compare = a < b;
    if(compare) a = b;
    return compare;
}
template<class T1, class T2>
inline bool chmin(T1 &a, const T2 b) noexcept {
    bool compare = a > b;
    if (compare) a = b;
    return compare;
}
/*************************
 vectorの最大値、最小値
**************************/
template<template<class, class> class T1, class T2, class T3>
inline T2 max(const T1<T2,T3> v) noexcept {
    return *max_element(all(v));
}
template<template<class, class> class T1, class T2, class T3>
inline T2 min(const T1<T2,T3> v) noexcept {
    return *min_element(all(v));
}
/***************************
 2次元vectorの最大値、最小値
****************************/
template<template<class, class> class T1, template<class, class> class T2, class T3, class T4, class T5>
T4 max(const T1<T2<T4, T5>, T3> v) noexcept {
    T4 maxValue;
    for (auto iter = v.begin(); iter < v.end(); ++iter) {
        if (iter == v.begin()) {
            maxValue = max(*iter);
        } else {
            chmax(maxValue, max(*iter));
        }
    }
    return maxValue;
}
template<template<class, class> class T1, template<class, class> class T2, class T3, class T4, class T5>
T4 min(const T1<T2<T4, T5>, T3> v) noexcept {
    T4 minValue;
    for (auto iter = v.begin(); iter < v.end(); ++iter) {
        if (iter == v.begin()) {
            minValue = min(*iter);
        } else {
            chmin(minValue, min(*iter));
        }
    }
    return minValue;
}

#ifdef __TEMPLATE__
#pragma endregion template
#endif

template<class T, const T& (* const op)(const T &, const T &) = max, const T e = T()>
struct SegTree {
    vector<T> tree, lazy;
    size_t n;
    const T LAZY_DEF = numeric_limits<T>::max();

    SegTree(const size_t N) noexcept {
        size_t tree_size = 2;
        while (tree_size < N) {
            tree_size *= 2;
        }
        tree = vector<T>(tree_size * 2, e);
        lazy = vector<T>(tree_size * 2, LAZY_DEF);
        n = tree_size;
    }

    SegTree(const vector<T> v) noexcept : SegTree(v.size()) {
        copy(v.begin(), v.end(), tree.begin() + n - 1);
        for (size_t i = n - 2; i >= 0; i--) {
            tree[i] = op(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
    }

    inline void delayed_evaluation(size_t node) {
        if (lazy[node] == LAZY_DEF) {
            return;
        }
        if (node < n - 1) {
            lazy[node * 2 + 1] = lazy[node];
            lazy[node * 2 + 2] = lazy[node];
        }
        tree[node] = lazy[node];
        lazy[node] = LAZY_DEF;
    }

    T update_all_sub(const size_t node) noexcept {
        delayed_evaluation(node);
        if (node < n - 1) {
            tree[node] = op(update_all_sub(node * 2 + 1), update_all_sub(node * 2 + 2));
        }
        return tree[node];
    }
    inline void update_all() noexcept {
        update_all_sub(0);
    }

    inline void set(const size_t p, const T x) noexcept {
        size_t node = n + p - 1;
        tree[node] = x;
        while (node > 0) {
            node = (node - 1) / 2;
            tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);
        }
    }

    void set(const size_t sl, const size_t sr, const T v, const size_t node, const size_t nl, const size_t nr) noexcept {
        delayed_evaluation(node);
        if (sl <= nl && nr <= sr) {
            lazy[node] = v;
            delayed_evaluation(node);
        } else if (sl < nr && nl < sr) {
            set(sl, sr, v, node * 2 + 1, nl, (nl + nr) / 2);
            set(sl, sr, v, node * 2 + 2, (nl + nr) / 2, nr);
            tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);
        }
    }
    inline void set(const size_t l, const size_t r, const T value) noexcept {
        set(l, r, value, 0, 0, n);
    }

    T query_sub(const size_t ql, const size_t qr, const size_t node, const size_t nl, const size_t nr) noexcept {
        delayed_evaluation(node);
        if (nr <= ql || qr <= nl) {
            return e;
        } else if (ql <= nl && nr <= qr) {
            return tree[node];
        } else {
            T vl = query_sub(ql, qr, node * 2 + 1, nl, (nl + nr) / 2);
            T vr = query_sub(ql, qr, node * 2 + 2, (nl + nr) / 2, nr);
            return op(vl, vr);
        }
    }
    // [l, r)
    inline T query(const size_t l, const size_t r) noexcept {
        return query_sub(l, r, 0, 0, n);
    }

    inline T query_all() noexcept {
        return tree[0];
    }
};

int main() {
    inputi(W,N);
    SegTree<int> seg(W);
    rep(N) {
        inputi(L,R);
        int h = seg.query(L - 1, R) + 1;
        print(h);
        seg.set(L - 1, R, h);
    }

    return 0;
}
