/* 縦、横、斜めの差分を取った時のやつ */    

    vvi sub(N,vi(N-1,0));
    // 横向き
    rep (i,0,N) {
        rep (j,0,N-1) {
            sub[i][j] = field[i][j+1] - field[i][j];
        }
    }
    chmax(ans, max_swipe(sub));
    
    fill(all(sub), vi(N-1,0));
    // 縦向き
    rep (i,0,N) {
        rep (j,0,N-1) {
            sub[i][j] = field[j+1][i] - field[j][i];
        }
    }
    chmax(ans, max_swipe(sub));
    
    sub.assign(2*N-3, vi(N-1,0));
    // 斜め（左下から右上／）
    rep(i,0,N) {
        rep(j,max(0,(i-N+2)),min(i,N-1)) {
            sub[i][j] = field[i-j][j+1] - field[i-j+1][j];
        }
    }
    chmax(ans, max_swipe(sub));
    
    fill(all(sub), vi(N-1,0));
    // 斜め（左上から右下\）
    rep(i,0,sub.size()) {
        rep(j,max(0,N-i-2),min(2*N-i-3,N-1)) {
            sub[i][j] = field[j-(N-i-2)+1][j+1] - field[j-(N-i-2)][j];
        }
    }
    chmax(ans, max_swipe(sub));
