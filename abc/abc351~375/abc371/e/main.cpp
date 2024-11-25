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

#define rep(i, x, limit) for (int i = (int)x; i < (int)limit; i++)
#define REP(i, x, limit) for (int i = (int)x; i <= (int)limit; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define YESNO(bool) if(bool){cout<<"YES"<<el;}else{cout<<"NO"<<el;}
#define yesno(bool) if(bool){cout<<"yes"<<el;}else{cout<<"no"<<el;}
#define YesNo(bool) if(bool){cout<<"Yes"<<el;}else{cout<<"No"<<el;}
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps )
#define inRange(x,l,r) (l <= x && x < r)
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

// pairとvectorを簡単に出力できるようにした
template<typename T1, typename T2>
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template<typename T>
std::ostream &operator<< (std::ostream &os, std::vector<T> v){
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? spa : "");
    }
    return os;
}
template<typename T>
std::ostream &operator<< (std::ostream &os, std::vector<std::vector<T>> v){
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i+1!=(int)v.size() ? "\n" : "");
    }
    return os;
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
    int N; cin>>N;

    vector<int> A(N);
    rep(i,0,N) cin>>A[i];

    vector<int> exist(200010,0);
    vector<int> s(N,0);
    exist[A[0]]++;
    s[0]=1;

    rep(i,1,N) {
        if (!exist[A[i]]) {
            s[i] = s[i-1] + 1; 
        } else {
            s[i] = s[i-1];
        }
        exist[A[i]]++;
    }

    int count = 0, dec = 0;
    rep(i,0,N) {
        if (i!=0) {
            exist[A[i-1]]--;
            if (!exist[A[i-1]]) {
                dec++;
            }
        }
        rep(j,i,N) {
            count += s[j]-dec;
        }
    }

    print(count);

    return 0;
}
