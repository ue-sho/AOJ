#include<iostream>
#include<vector>
using namespace std;

constexpr int N = 4, N_2D = 16;
constexpr int MAX_LIMIT = 45;

struct Pazzle{
    int location[N_2D];
    int space;
    int MD; // マンハッタン距離の総距離
};

/**
 *  マンハッタン距離の計算
 *  (上下左右だけの移動の総距離)
 */ 
int calc_all_MD(const Pazzle& pazzle, const vector<vector<int>>& manhattan_distanc){
    int res = 0;
    for(int i = 0; i < N_2D; ++i){
        if(pazzle.location[i] == N_2D){
            continue;
        }
        res += manhattan_distanc[i][pazzle.location[i]-1];
    }
    return res;
}

/**
 *  深さ優先探索
 */ 
bool dfs(const int depth, vector<vector<int>>& manhattan_distanc, 
            Pazzle& state, const int limit, int& ans, const int prev = -50){

    if(state.MD == 0){
        ans = depth;    // 一致したら終わり
        return true;
    }

    if(state.MD + depth > limit){
        return false;
    }

    int sx = state.space / N;   // space x
    int sy = state.space % N;   // space y

    constexpr int dx[4] = {0, 1, 0, -1};
    constexpr int dy[4] = {1, 0, -1, 0};

    for(int i = 0; i < 4; ++i){
        int tx = sx + dx[i];    // transfer x
        int ty = sy + dy[i];    // transfer y

        if(tx < 0 || tx >= N || ty < 0 || ty >= N){
            continue;   // 移動先がパズルの枠を超えてしまわないようにする
        }
        if(abs(prev - i) == 2){
            continue;   // 隣じゃなかったら
        }

        Pazzle tmp = state;
        state.MD -= manhattan_distanc[tx*N+ty][state.location[tx*N+ty]-1];
        state.MD += manhattan_distanc[sx*N+sy][state.location[tx*N+ty]-1];
        // spaceの位置を移動
        swap(state.location[tx * N + ty], state.location[sx * N + sy]);
        state.space = tx * N + ty;
        state.MD = calc_all_MD(state, manhattan_distanc);
        if(dfs(depth+1, manhattan_distanc, state, limit, ans, i)){
            return true;
        }
        state = tmp;  // 失敗したら元に戻す
    }
    return false;
}

/**
 *  反復深化
 */ 
void iterative_deepening(Pazzle& pazzle, vector<vector<int>>& manhattan_distance){
    pazzle.MD = calc_all_MD(pazzle, manhattan_distance);
    
    int ans = 0;
    Pazzle state;
    for(int limit = pazzle.MD; limit <= MAX_LIMIT; ++limit){
        state = pazzle;
        if(dfs(0, manhattan_distance, state, limit, ans)){
            cout << ans << endl;
            return;
        }
    }
}

int main(){

    vector<vector<int>> manhattan_distance(N_2D, vector<int>(N_2D));
    for (int i = 0; i < N_2D; ++i){
        for (int j = 0; j < N_2D; ++j){
            manhattan_distance[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Pazzle pazzle;
    for (int i = 0; i < N_2D; ++i){
        cin >> pazzle.location[i];
        if (pazzle.location[i] == 0){
            pazzle.location[i] = N_2D;
            pazzle.space = i;
        }
    }

    iterative_deepening(pazzle, manhattan_distance);

    return 0;
}