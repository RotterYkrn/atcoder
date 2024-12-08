#ifdef __TEMPLATE__
#pragma region template
#endif

#include <bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
// using mint = modint998244353;
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
#define el '\n'
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
constexpr int dx[4] = { 0, 1, 0,-1};

// 8方向 左上, 上, 右上, 右, 右下, 下, 左下, 左
constexpr int dy8[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
constexpr int dx8[8] = {-1, 0, 1, 1, 1, 0,-1,-1};

/***************************************
 mkvec<type>(n or {n1,n2,...}[, init])
****************************************/
template<class T>
inline auto mkvec(const auto d, const T& init = T{}) noexcept {
    return vector<T>(d, init);
}
template<class T, size_t n, size_t idx = 0>
auto mkvec(const auto (&d)[n], const T& init = T{}) noexcept {
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
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << (i + 1 != (int)v.size() ? "\n" : "");
        }
    } else {
        for (int i = 0; i < (int)v.size(); i++) {
            os << v[i] << (i + 1 != (int)v.size() ? spa : "");
        }
    }
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? "\n" : "");
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
#define inputi(...)    int __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputll(...)    ll __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputs(...) string __VA_ARGS__; input_cin(__VA_ARGS__);
template <class T>
inline auto inputv(const auto d) {
    vector<T> vec(d);
    for (int i = 0; i < d; i++) {
        cin >> vec[i];
    }
    return vec;
}
template<class T, size_t n, size_t idx = 0>
auto inputv(const auto (&d)[n]) noexcept {
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
    for (auto iter = v.begin(); iter < v.end(); ++iter) {
        chmax(maxValue, max(*iter));
    }
    return maxValue;
}
template<class T>
T min(const vector<vector<T>> v) noexcept {
    T minValue = numeric_limits<T>::max();
    for (auto iter = v.begin(); iter < v.end(); ++iter) {
        chmin(minValue, min(*iter));
    }
    return minValue;
}

#ifdef __TEMPLATE__
#pragma endregion template
#endif


int main() {
    inputll(N);
    ll lim = (ll)(sqrt(N)) + 1L;
    auto prime_tmp = mkvec<int>(lim, 1);
    prime_tmp[0] = prime_tmp[1] = 0;
    auto prime = mkvec<ll>(0);
    for (ll i = 2; i < lim; i++) {
        if (prime_tmp[i]) {
            prime.pb(i);
            for (ll j = i * i; j < lim; j += i) {
                prime_tmp[j] = 0;
            }
        }
    }

    ll ans = 0;
    rep(i, prime.size()) {
        ll tmp = prime[i];
        bool judge = true;
        rep(3) {
            if (tmp > lim - 1L) {
                judge = false;
                break;
            }
            tmp *= tmp;
        }
        if (judge) ans++;
        if (prime[i] * prime[i] * prime[i + 1] * prime[i + 1] > N) break;
        rep(j, i + 1, prime.size()) {
            if (prime[i] * prime[i] * prime[j] * prime[j] <= N) ans++;
            else break;
        }
    }
    print(ans);

    return 0;
}
