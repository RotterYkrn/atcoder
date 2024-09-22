#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

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
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define eps (1e-10)
#define Equals(a,b) (fabs((a) - (b)) < eps )
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


template<typename T1, typename T2>
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "{" << p.first << "," << p.second << "}";
    return os;
}

// 配列の要素を空白区切りで出力 第二引数をtrueにすると改行区切り
template<typename T> inline void print_vec(const vector<T> &v, bool split_line=false) {
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    constexpr bool isValue = is_integral<T>::value;
    for (int i = 0; i < (int)v.size(); i++) {
        if constexpr(isValue){
            if((v[i]==inf) || (v[i]==infl)) cout << 'x' << " \n"[split_line || i+1==(int)v.size()];
            else cout << v[i] << " \n"[split_line || i+1==(int)v.size()];
        }else cout << v[i] << " \n"[split_line || i+1==(int)v.size()];
    }
}

template<typename T1, typename T2> inline void print_vec(const vector<pair<T1,T2>> &v, bool split_line=false){
    if(v.empty()){
        cout << "This vector is empty." << el;
        return;
    }
    for(int i = 0; i < (int)v.size(); i++){
        cout << '{';
        auto [a,b] = v[i];
        constexpr pair<bool,bool> isValue = {is_integral<T1>::value, is_integral<T2>::value};
        if constexpr(isValue.first){
            if(a==inf || a==infl) cout << "x,";
            else cout << a << ",";
        }else cout << a << ",";
        if constexpr(isValue.second){
            if(b==inf || b==infl) cout << "x,";
            else cout << b;
        }else cout << b;
        cout << "}" << " \n"[split_line || i+1==(int)v.size()];
    }
}

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
    int L,R;
    cin >> L >> R;

    if (L && !R) {
        Yes;
    } else if (!L && R) {
        No;
    } else {
        cout << "Invalid" << el;
    }

    return 0;
}
