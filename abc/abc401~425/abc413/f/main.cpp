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

struct State {
    int i, j, dir;
    ll dist;
};

int main() {
    inputi(H, W, K);
    auto grid = mkvec<pair<pil, pil>>({H,W}, {{-1, -1}, {-1, -1}});
    queue<State> que;
    rep(K) {
        inputi(h, w);
        --h; --w;
        que.push({h, w, 4, 0});
    }

    while (!que.empty()) {
        auto [i, j, dir, dist] = que.front();
        que.pop();

        if (grid[i][j].second.first != -1 && dir != 4) continue;

        if (dir == 4) {
            grid[i][j].first = {4, 0};
            grid[i][j].second = {4, 0};
        } else {
            if (grid[i][j].first.first == -1) {
                grid[i][j].first = {dir, dist};
            } else {
                grid[i][j].second = {dir, dist};
            }
        }

        rep(k, 4) {
            int ni = i + dy[k], nj = j + dx[k];
            if (!ir(ni, H) || !ir(nj, W) || grid[ni][nj].second.first != -1) continue;
            que.push({ni, nj, (k + 2) % 4, dist + 1});
        }
    }

    auto dp = mkvec<ll>({H,W}, -1);
    auto f = [&](auto f, int i, int j, int pi, int pj, int blocked) -> ll {
        int dir1 = grid[i][j].first.first, dir2 = grid[i][j].second.first;
        ll dist1 = grid[i][j].first.second, dist2 = grid[i][j].second.second;

        if (dir1 == 4) {
            return dp[i][j] = 0;
        }

        int dir, block_d;
        if (dist1 == dist2) {
            if (dir1 != blocked) {
                dir = dir1;
                block_d = dir2;
            } else {
                dir = dir2;
                block_d = dir1;
            }
        } else {
            dir = dir2;
            block_d = dir1;
        }

        int ni = i + dy[dir], nj = j + dx[dir];
        if (ni == pi && nj == pj) {
            return dp[i][j] = 0;
        }

        ll res = f(f, ni, nj, i, j, block_d);
        int nd = grid[ni][nj].second.first;

        if (res == 0LL && nd != 4) {
            return dp[i][j] = 0;
        } else {
            return dp[i][j] = res + 1;
        }
    };

    ll ans = 0;
    rep(i, H) rep(j, W) {
        if (dp[i][j] == -1) {
            f(f, i, j, -1, -1, -1);
        }
        ans += dp[i][j];
    }

    print(grid, dp);

    print(ans);

    return 0;
}
