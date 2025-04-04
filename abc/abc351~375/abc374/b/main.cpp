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

#define OVERLOAD_MACRO(_1, _2, _3, name, ...) name
// loop [begin,end)
#define REP1(i, end) for (auto i = decay_t<decltype(end)>{}; (i) != (end); ++(i))
#define REP2(i, begin, end) for (auto i = (begin); (i) != (end); ++(i))
#define rep(...) OVERLOAD_MACRO(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
// loop [rend,rbegin)
#define RREP1(i, rbegin) for (auto i = (rbegin-1); i >= 0; i--)
#define RREP2(i, rbigin, rend) for (auto i = (rend-1); (i) >= (rbegin); i--)
#define rrep(...) OVERLOAD_MACRO(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
// is in [l,r)
#define INRANGE1(x, r) (0 <= x && x < r)
#define INRANGE2(x, l, r) (l <= x && x < r)
#define inRange(...) OVERLOAD_MACRO(__VA_ARGS__, INRANGE2, INRANGE1)(__VA_ARGS__)

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
    if constexpr (idx < n) return vector(d[idx], mkvec<T, n, idx + 1>(d, init));
    else return init;
}
#define vi mkvec<int>
#define vs mkvec<string>
#define vb mkvec<bool>
#define vpii mkvec<pii>
#define vpll mkvec<pll>

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
#define inputs(...) string __VA_ARGS__; input_cin(__VA_ARGS__);

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


int main() {
    inputs(S,T);

    if (S == T) {
        print(0);
    } else {
        rep(i,min(S.size(),T.size())) {
            if (S.at(i) != T.at(i)) {
                print(i+1);
                return 0;
            }
        }
        print(min(S.size(),T.size())+1);
    }

    return 0;
}
