#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

// おまじない
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); } }init;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using Graph = vvi;

#define rep(i, begin, end) for (int i = (int)begin; i < (int)end; i++) // [begin,end)
#define rrep(i, rbigin, rend) for (int i = (int)rbigin-1; i >= (int)rend; i--) // [rend,rbegin)
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
#define inRange(l,r,x) (l <= x && x < r)
#define isNum(s) all_of(all(s), [](char c){ return isdigit(c); })
#define debug(x) cerr << #x << " = " << x << el

const int inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

// 4近傍、(一般的に)上右下左
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

// 8方向 左上, 上, 右上, 右, 右下, 下, 左下, 左
const int dy8[8] = {-1,-1,-1,0,1,1,1,0};
const int dx8[8] = {-1,0,1,1,1,0,-1,-1};

// pairとvectorを簡単に出力できるようにした
template<typename T1, typename T2>
ostream &operator<< (ostream &os, pair<T1,T2> p){
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template<typename T>
ostream &operator<< (ostream &os, vector<T> v){
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? spa : "");
    }
    return os;
}
ostream &operator<< (ostream &os, vector<string> v){
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? "\n" : "");
    }
    return os;
}
template<typename T>
ostream &operator<< (ostream &os, vector<vector<T>> v){
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? "\n" : "");
    }
    return os;
}

// Pythonのprintみたいな
inline void print() {
    cout << el;
}
template <typename T>
inline void print(const T& t) {
    cout << t << el;
}
template <typename First, typename... Rest>
void print(const First& first, const Rest&... rest) {
    cout << first << " ";
    print(rest...); // recursive call using pack expansion syntax
}

// 値が大きい、小さい方を代入
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 b) {
    bool compare = a < b;
    if(compare) a = b;
    return compare;
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 b) {
    bool compare = a > b;
    if(compare) a = b;
    return compare;
}
// vectorの最大値、最小値
template<template<typename, typename> typename T1, typename T2, typename T3>
inline T2 max(const T1<T2,T3> v) {
    return *max_element(all(v));
}
template<template<typename, typename> typename T1, typename T2, typename T3>
inline T2 min(const T1<T2,T3> v) {
    return *min_element(all(v));
}
// 2次元vectorの最大値、最小値
template<template<typename, typename> typename T1, template<typename, typename> typename T2, typename T3, typename T4, typename T5>
T4 max(const T1<T2<T4, T5>, T3> v) {
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
template<template<typename, typename> typename T1, template<typename, typename> typename T2, typename T3, typename T4, typename T5>
T4 min(const T1<T2<T4, T5>, T3> v) {
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
    

    return 0;
}
