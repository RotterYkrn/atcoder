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

#define pb push_back
#define mp make_pair
#define el '\n'
#define spa " "

constexpr int inf = 1073741823;
constexpr ll infl = 1LL << 60;

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

/***************************************
 pairとvectorを簡単に出力できるようにした
****************************************/
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

void rec(const int i, const auto g, auto &x) {
    if (!g[i].size()) return;
    if (x[i] == infl) x[i] = 0;
    for (auto w: g[i]) {
        if (x[w.first] == infl) {
            x[w.first] = x[i] + w.second;
            if (g[i].size()) {
                rec(w.first, g, x);
            }
        }
    }
}

int main() {
    inputi(N,M);

    auto graph = mkvec<pii>({N,0});
    rep(i,M) {
        inputi(u,v,w);
        u--; v--;
        graph[u].pb(mp(v,w));
    }

    auto x = mkvec<ll>(N,infl);
    rep(i,N) {
        if (graph[i].size()) {
            rec(i, graph, x);
        }
    }

    print(x);

    return 0;
}
