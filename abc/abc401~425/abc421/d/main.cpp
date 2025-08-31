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
// using mint = modint;
// mint::set_mod(MOD);
#endif

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;

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
#define IN_RANGE1(x, r)    (0 <= x && x < r)
#define IN_RANGE2(x, l, r) (l <= x && x < r)
#define ir(...) OVERLOAD_MACRO(__VA_ARGS__, IN_RANGE2, IN_RANGE1)(__VA_ARGS__)
// from range to iterator [left, right)
#define RANGE_TO_ITERATOR1(arr, left) arr.begin() + (left), arr.end()
#define RANGE_TO_ITERATOR2(arr, left, right) arr.begin() + (left), arr.begin() + (right)
#define rtoit(...) OVERLOAD_MACRO(__VA_ARGS__, RANGE_TO_ITERATOR2, RANGE_TO_ITERATOR1)(__VA_ARGS__)

#define pb push_back
#define mp make_pair
#define all(container) container.begin(), container.end()
#define rall(container) container.rbegin(), container.rend()
#define YES cout << "YES\n"
#define NO  cout << "NO\n"
#define Yes cout << "Yes\n"
#define No  cout << "No\n"
#define yes cout << "yes\n"
#define no  cout << "no\n"
#define YESNO(bool) if(bool) YES; else NO
#define YesNo(bool) if(bool) Yes; else No
#define yesno(bool) if(bool) yes; else no
#define isNum(s) all_of(all(s), [](char c){ return isdigit(c); })

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

template <class T>
struct is_container : false_type { };
template<template <class...> class Container, class T>
struct is_container<Container<T>> : std::true_type { };
template <class T>
inline constexpr bool is_container_v = is_container<T>::value;

/***************************************
 mkvec<type>(n or {n1,n2,...}[, init])
****************************************/
template<class T>
inline auto mkvec(const auto d, const T &init = T{}) {
    return vector<T>(d, init);
}
template<class T, size_t n, size_t idx = 0>
auto mkvec(const auto (&d)[n], const T &init = T{}) {
    if constexpr (idx < n - 1) return vector(d[idx], mkvec<T, n, idx + 1>(d, init));
    else return mkvec<T>(d[idx], init);
}

/***************************************
 pairとコンテナを簡単に出力できるようにした
****************************************/
template<class First, class Second>
ostream &operator<<(ostream &os, const pair<First, Second> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> v) {
    if constexpr (is_same_v<T, string>) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            os << *it << (next(it) != v.end() ? "\n" : "");
        }
    } else {
        for (auto it = v.begin(); it != v.end(); ++it) {
            os << *it << (next(it) != v.end() ? " " : "");
        }
    }
    return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << *it << (next(it) != v.end() ? "\n" : "");
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
    input_cin(rest...);
}
#define inputi(...)    int __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputll(...)    ll __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputc(...)   char __VA_ARGS__; input_cin(__VA_ARGS__);
#define inputs(...) string __VA_ARGS__; input_cin(__VA_ARGS__);
template<class First, class Second>
istream &operator>>(istream &in, pair<First, Second> &p) {
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
auto inputv(const D(&d)[n]) {
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
    cout << "\n";
}
template <bool new_line = false, class T>
inline void print(const T &t) {
    if (new_line && is_container_v<T>) {
        cout << "\n";
    }
    cout << t << "\n";
}
template <bool new_line = false, class First, class... Rest>
void print(const First &first, const Rest&... rest) {
    if (new_line && is_container_v<First>) {
        cout << "\n";
    }
    cout << first << (is_container_v<First> ? "\n" : " ");
    print<!is_container_v<First>>(rest...);
}

/*************************
 値が大きい、小さい方を代入
**************************/
template<class T1, class T2>
inline bool chmax(T1 &a, const T2 b) {
    bool compare = a < b;
    if (compare) a = b;
    return compare;
}
template<class T1, class T2>
inline bool chmin(T1 &a, const T2 b) {
    bool compare = a > b;
    if (compare) a = b;
    return compare;
}
/*************************
 vectorの最大値、最小値
**************************/
template<class T>
inline T max(const vector<T> v) {
    return *max_element(all(v));
}
template<class T>
inline T min(const vector<T> v) {
    return *min_element(all(v));
}
/***************************
 2次元vectorの最大値、最小値
****************************/
template<class T>
T max(const vector<vector<T>> v) {
    T maxValue = numeric_limits<T>::lowest();
    for (const auto &i : v) {
        chmax(maxValue, max(i));
    }
    return maxValue;
}
template<class T>
T min(const vector<vector<T>> v) {
    T minValue = numeric_limits<T>::max();
    for (const auto &i : v) {
        chmin(minValue, min(i));
    }
    return minValue;
}

#ifdef __TEMPLATE__
#pragma endregion template
#endif

typedef struct Point_Coordinates {
    ll x, y;
} point;

// 線分ab, cdが交差する場合True
// 端点が他方の線分上にある場合もTrue
// 端点が他方の線分の延長線上にある場合もTrueを返すので注意
int Judge(point &&a, point &&b, point &&c, point &&d) {
    ll s, t;
    s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
    t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
    if (s * t > 0)
        return false;

    s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
    t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
    if (s * t > 0)
        return false;
    return true;
}

bool target(char c, ll sr, ll sc, ll er, ll ec, ll cnt) {
    ll cur, tgt;
    switch (c) {
    case 'U':
    case 'D':
        cur = sr;
        tgt = er;
        return abs(cur - tgt) == cnt;
    case 'L':
    case 'R':
        cur = sc;
        tgt = ec;
        return abs(cur - tgt) == cnt;
    }
}

int main() {
    inputll(Rt, Ct, Ra, Ca);
    inputll(N, M, L);

    auto TM = mkvec<pair<char, ll>>(M);
    rep(i, M) {
        inputc(c);
        inputll(m);
        TM[i] = {c, m};
    }

    auto AM = mkvec<pair<char, ll>>(L);
    rep(i, L) {
        inputc(c);
        inputll(m);
        AM[i] = {c, m};
    }

    ll ans = 0, rt = Rt, ct = Ct, ra = Ra, ca = Ca;
    ll i = 0, j = 0;
    while (i < M && j < L) {
        auto &[ts, ta] = TM[i];
        auto &[as, aa] = AM[j];

        ll drt, dct;
        if (ts == 'R') dct = 1;
        else if (ts == 'L') dct = -1;
        else dct = 0;
        if (ts == 'U') drt = -1;
        else if (ts == 'D') drt = 1;
        else drt = 0;

        ll dra, dca;
        if (as == 'R') dca = 1;
        else if (as == 'L') dca = -1;
        else dca = 0;
        if (as == 'U') dra = -1;
        else if (as == 'D') dra = 1;
        else dra = 0;

        ll cnt = min(ta, aa);
        if (Judge({rt, ct}, {rt + drt * cnt, ct + dct * cnt}, {ra, ca}, {ra + dra * cnt, ca + dca * cnt})) {
            if (ts == 'R' && as == 'L'
                || ts == 'L' && as == 'R') {
                if (ct != ca && (ct - ca) % 2 == 0) {
                    ans++;
                }
            } else if (
                ts == 'U' && as == 'D'
                || ts == 'D' && as == 'U') {
                if (rt != ra && (rt - ra) % 2 == 0) {
                    ans++;
                }
            } else if (
                ts == 'U' && as == 'U'
                || ts == 'D' && as == 'D') {
                if (rt == ra) {
                    ans += cnt;
                }
            } else if (
                ts == 'L' && as == 'L'
                || ts == 'R' && as == 'R') {
                if (ct == ca) {
                    ans += cnt;
                }
            } else {
                if (target(ts, rt, ct, ra, ca, cnt)
                    && target(as, ra, ca, rt, ct, cnt)) {
                    ans++;
                }
            }
        }

        rt += drt * cnt;
        ct += dct * cnt;
        ra += dra * cnt;
        ca += dca * cnt;

        ta -= cnt;
        aa -= cnt;

        if (ta == 0) {
            i++;
        }
        if (aa == 0) {
            j++;
        }
    }

    print(ans);

    return 0;
}
