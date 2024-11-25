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
using vii = vector<vi>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using Graph = vii;

#define rep(i, begin, end) for (int i = (int)begin; i < (int)end; i++)
#define rrep(i, rbigin, rend) for (int i = (int)rbigin-1; i >= (int)rend; i--)
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
#define YESNO(bool) if(bool){cout<<"YES"<<el;}else{cout<<"NO"<<el;}
#define yesno(bool) if(bool){cout<<"yes"<<el;}else{cout<<"no"<<el;}
#define YesNo(bool) if(bool){cout<<"Yes"<<el;}else{cout<<"No"<<el;}
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps)
#define inRange(l,r,x) (l <= x && x < r)
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
void print() {
    cout << el;
}
template <typename T> void print(const T& t) {
    cout << t << el;
}
template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    cout << first << " ";
    print(rest...); // recursive call using pack expansion syntax
}

// 値が大きい（小さい）方を代入
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    bool compare = a < b;
    if(compare) a = b;
    return compare;
}
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    bool compare = a > b;
    if(compare) a = b;
    return compare;
}


int main() {
    

    return 0;
}
