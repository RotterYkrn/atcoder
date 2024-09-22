#include <bits/stdc++.h>
using namespace std;

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
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
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
    cout << endl;
}
template <typename T> void print(const T& t) {
    cout << t << endl;
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

void DFS(int h, int w, vector<string> &f) {
    f[h].at(w) = '.';
    rep (i,0,4) {
        int nh=h+dx[i], nw=w+dy[i];
        if (inRange(nh,0,f.size()) && inRange(nw,0,f[0].size())) {
            if (f[nh].at(nw)=='#') {
                DFS(nh, nw, f);
            }
        }
    }
    return;
}


int main() {
    int H,W; cin>>H>>W;
    vector<string> field(H);
    rep(i,0,H) cin>>field[i];
    
    pair<pair<int,int>, pair<int,int>> likes(pair<int,int>(-1,-1), pair<int,int>(-1,-1));
    bool finished = false;
    rep(i,0,H) {
        rep(j,0,W) {
            if (field[i].at(j)=='#') {
                if (likes.first.first == -1) {
                    likes.first = make_pair(i,j);
                } else {
                    likes.second = make_pair(i,j);
                    finished = true;
                    break;
                }
            }
        }
        if (finished) {
            break;
        }
    }

    ull cnt = 0;
    rep (i,0,H) rep(j,0,W) {
        if (field[i].at(j)=='#') {
            vector<string> built(field.size());
            copy(all(field), built.begin());
            built[i].at(j) = '.';
            if (i!=likes.first.first || j!=likes.first.second) {
                DFS(likes.first.first,likes.first.second,built);
            } else {
                DFS(likes.second.first,likes.second.second,built);
            }
            print(built);
            bool canBuild = true;
            rep (k,0,H) {
                if (built[k].find('#') != string::npos) {
                    canBuild = false;
                    break;
                }
            }
            print(canBuild);
            if (canBuild) {
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    
    print(cnt);

    return 0;
}
