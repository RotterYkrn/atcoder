/*****************
  1次元バージョン
******************/
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    int group;
    
    explicit UnionFind(const int N) : par(N), rank(N), group(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int root(const int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(const int x, const int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        if (rank[rx] < rank[ry]){
            par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        } else {
            par[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
        group--;
    }
    
    bool same(const int x, const int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        return root(x) == root(y);
    }
};

/*****************
  2次元バージョン
******************/
struct UnionFind {
    vector<vector<pair<int, int>>> par; // par[i][j]:(i,j)の親の番号　(例) par[3][4] = {2,5} : (3,4)の親が(2,5)
    vector<vector<int>> rank;
    int group;
    
    UnionFind(const int N, const int M) : par(N, vector<pair<int, int>>(M)), rank(N, vector<int>(M)), group(N * M) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                par[i][j] = {i, j};
                rank[i][j] = 0;
            }
        }
    }
    
    pii root(const pair<int, int> x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x.first][x.second] == x) return x;
        return par[x.first][x.second] = root(par[x.first][x.second]);
    }
    
    void unite(const pair<int, int> x, const pair<int, int> y) { // xとyの木を併合
        pair<int, int> rx = root(x); //xの根をrx
        pair<int, int> ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        if (rank[rx.first][rx.second] < rank[ry.first][ry.second]){
            par[rx.first][rx.second] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        } else {
            par[ry.first][ry.second] = rx;
            if (rank[rx.first][rx.second] == rank[ry.first][ry.second]) rank[rx.first][rx.second]++;
        }
        group--;
    }
    
    bool same(const pair<int, int> x, const pair<int, int> y) { // 2つのデータx, yが属する木が同じならtrueを返す
        return root(x) == root(y);
    }
};
