#ifdef __TEMPLATE__
#pragma region template
#endif

#include <bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#endif

// おまじない
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define OVERLOAD_MACRO(_1, _2, _3, name, ...) name
// loop [begin,end)
#define REP0(end)           for (auto _ = decay_t<decltype(end)>{};      (_) != (end); ++(_))
#define REP1(i, end)        for (auto i = decay_t<decltype(end)>{};      (i) != (end); ++(i))
#define REP2(i, begin, end) for (auto i = decay_t<decltype(end)>{begin}; (i) != (end); ++(i))
#define rep(...) OVERLOAD_MACRO(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)
// reveres loop [rend,rbegin)
#define RREP1(i, rbegin)       for (auto i = (rbegin - 1); (i) >= decay_t<decltype(rbegin)>{};     --(i))
#define RREP2(i, rbegin, rend) for (auto i = (rbegin - 1); (i) >= decay_t<decltype(rbegin)>{rend}; --(i))
#define rrep(...) OVERLOAD_MACRO(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
// is in [l,r)
#define INRANGE1(x, r)    (0 <= x && x < r)
#define INRANGE2(x, l, r) (l <= x && x < r)
#define ir(...) OVERLOAD_MACRO(__VA_ARGS__, INRANGE2, INRANGE1)(__VA_ARGS__)
// from range to iterator [left, right)
#define RANGE_TO_ITERATOR1(arr, left) arr.begin() + (left), arr.end()
#define RANGE_TO_ITERATOR2(arr, left, right) arr.begin() + (left), arr.begin() + (right)
#define rtoit(...) OVERLOAD_MACRO(__VA_ARGS__, RANGE_TO_ITERATOR2, RANGE_TO_ITERATOR1)(__VA_ARGS__)

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el "\n"
#define spa " "
#define Yes cout << "Yes" << el
#define No  cout << "No" << el
#define yes cout << "yes" << el
#define no  cout << "no" << el
#define YES cout << "YES" << el
#define NO  cout << "NO" << el
#define YESNO(bool) if(bool) { cout << "YES" << el; } else { cout << "NO" << el; }
#define YesNo(bool) if(bool) { cout << "Yes" << el; } else { cout << "No" << el; }
#define yesno(bool) if(bool) { cout << "yes" << el; } else { cout << "no" << el; }
#define eps (1e-10)
#define Equals(a, b) (fabs((a) - (b)) < eps)
#define isNum(s) all_of(all(s), [](char c){ return isdigit(c); })
#define debug(x) cerr << #x << " = " << x << el

constexpr int inf = 1073741823;
constexpr ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

// 4近傍、(一般的に)上右下左
constexpr int dy[4] = {-1, 0, 1, 0};
constexpr int dx[4] = {0, 1, 0,-1};

// 8方向 左上, 上, 右上, 右, 右下, 下, 左下, 左
constexpr int dy8[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
constexpr int dx8[8] = {-1, 0, 1, 1, 1, 0,-1,-1};

template <typename T>
struct is_vector : std::false_type { };
template <typename T, typename Allocator>
struct is_vector<std::vector<T, Allocator>> : std::true_type { };
template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

/***************************************
 mkvec<type>(n or {n1,n2,...}[, init])
****************************************/
template<class T>
inline auto mkvec(const auto d, const T &init = T{}) noexcept {
    return vector<T>(d, init);
}
template<class T, size_t n, size_t idx = 0>
auto mkvec(const auto (&d)[n], const T &init = T{}) noexcept {
    if constexpr (idx < n - 1) return vector(d[idx], mkvec<T, n, idx + 1>(d, init));
    else return mkvec<T>(d[idx], init);
}

/***************************************
 pairとvectorを簡単に出力できるようにした
****************************************/
template<class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> v) {
    if constexpr (is_same_v<T, string>) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            os << *it << (it + 1 != v.end() ? el : "");
        }
    } else {
        for (auto it = v.begin(); it != v.end(); ++it) {
            os << *it << (it + 1 != v.end() ? spa : "");
        }
    }
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << *it << (it + 1 != v.end() ? el : "");
    }
    return os;
}

/***************
 複数の標準入力
****************/
template <class T>
inline void input_cin(T &val) {
    cin >> val;
}
template <class First, class... Rest>
void input_cin(First &first, Rest&... rest) {
    cin >> first;
    input_cin(rest...); // recursive call using pack expansion syntax
}
#define inputi(...)    int __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputll(...)    ll __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputs(...) string __VA_ARGS__; input_cin(__VA_ARGS__);
template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}
template <class T>
inline auto inputv(const auto d) {
    vector<T> vec(d);
    for (auto &i : vec) {
        cin >> i;
    }
    return vec;
}
template<class T, class D, size_t n, size_t idx = 0>
auto inputv(const D(&d)[n]) noexcept {
    if constexpr (idx < n - 1) {
        D d_make[n - idx];
        copy(begin(d) + idx, end(d), begin(d_make));
        auto vec = mkvec<T>(d_make);
        for (auto &i : vec) {
            i = inputv<T, D, n, idx + 1>(d);
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
template <bool new_line = false, class T>
inline void print(const T &t) {
    if (new_line && is_vector_v<T>) {
        cout << el;
    }
    cout << t << el;
}
template <bool new_line = false, class First, class... Rest>
void print(const First &first, const Rest&... rest) {
    if (new_line && is_vector_v<First>) {
        cout << el;
    }
    cout << first << (is_vector_v<First> ? el : " ");
    print<!is_vector_v<First>>(rest...); // recursive call using pack expansion syntax
}

/*************************
 値が大きい、小さい方を代入
**************************/
template<class T1, class T2>
inline bool chmax(T1 &a, const T2 b) noexcept {
    bool compare = a < b;
    if (compare) a = b;
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
template<class T>
inline T max(const vector<T> v) noexcept {
    return *max_element(all(v));
}
template<class T>
inline T min(const vector<T> v) noexcept {
    return *min_element(all(v));
}
/***************************
 2次元vectorの最大値、最小値
****************************/
template<class T>
T max(const vector<vector<T>> v) noexcept {
    T maxValue = numeric_limits<T>::lowest();
    for (const auto &i : v) {
        chmax(maxValue, max(i));
    }
    return maxValue;
}
template<class T>
T min(const vector<vector<T>> v) noexcept {
    T minValue = numeric_limits<T>::max();
    for (const auto &i : v) {
        chmin(minValue, min(i));
    }
    return minValue;
}

#ifdef __TEMPLATE__
#pragma endregion template
#endif


int main() {
    inputs(S);

    int ans = 0;
    rep(i, S.size()) {
        if (i + 1 < S.size() && S[i] == '0' && S[i + 1] == '0') {
            i++;
        }
        ans++;
    }

    print(ans);

    return 0;
}
