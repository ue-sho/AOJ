#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int matrix[N][N] = {};
int color[N] = {};
int start[N], completed[N], now = 0;

void dfs_visit(int unfixed, int n){
    
    color[unfixed] = GRAY;
    start[unfixed] = ++now;

    rep(i, n){
        if(matrix[unfixed][i] == 0){
            continue;
        }
        if(color[i] == WHITE){
            dfs_visit(i, n);
        }
}
    color[unfixed] = BLACK;
    completed[unfixed] = ++now;
}

void dfs(int n){
    rep(i, n){
        if(color[i] == WHITE){
            dfs_visit(i, n);
        }
    }
    rep(i, n){
        cout << i+1 << " " << start[i] << " " << completed[i] << endl;
    }
}

int main() {

    int n;
    cin >> n;
    rep(i, n){
        int k, l;
        cin >> k >> l;
        rep(j, l){
            int v;
            cin >> v;
            matrix[k-1][v-1] = 1;
        }
    }

    dfs(n);

    return 0;
}