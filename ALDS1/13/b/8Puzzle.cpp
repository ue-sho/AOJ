#include<iostream>
#include<queue>
#include<map>
using namespace std;

constexpr int N = 3, N_2D = 9;

class Puzzle {
public:
    int location[N_2D];
    int space;
    string path;

    bool operator<(const Puzzle& puzzle) const {
        for(int i = 0; i < N_2D; ++i){
            if(location[i] == puzzle.location[i]){
                continue;
            }
            return location[i] > puzzle.location[i];
        }
        return false;
    }
};

/**
 *  位置があっているかどうか判定する 
 */
bool isTarget(const Puzzle& puzzle){
    for(int i = 0; i < N_2D; ++i){
        if(puzzle.location[i] != i+1){
            return false;
        }
    }
    return true;
}

/**
 *  幅優先探索
 */ 
string bfs(Puzzle& origin){
    queue<Puzzle> que;
    map<Puzzle, bool> mp;    // 配置を記録していく
    origin.path = "";
    que.push(origin);
    mp[origin] = true;

    constexpr int dx[] = {-1, 0, 1, 0};
    constexpr int dy[] = {0, -1, 0, 1};
    constexpr char direction[] = {'u', 'l', 'd', 'r'};
                                // up, left, down, right 
    while(!que.empty()){
        Puzzle parent = que.front(); 
        que.pop();
        if(isTarget(parent)){    // もしパズルuがターゲットと合致していれば終わり
            return parent.path;
        }
        int sx = parent.space / N;   // space x
        int sy = parent.space % N;   // space y

        for(int i = 0; i < 4; ++i){
            int tx = sx + dx[i];    // transfer x
            int ty = sy + dy[i];    // transfer y
            if(tx < 0 || ty < 0 || tx >= N || ty >= N){
                continue;    // 移動先がパズルの枠を超えてしまわないようにする
            }
            
            Puzzle child = parent;
            swap(child.location[parent.space], child.location[tx*N + ty]);
            child.space = tx*N + ty;    // spaceの位置も移動
            
            if(!mp[child]){    // 既に同じ配置のパズルを動かし済みの場合はスルーする
                mp[child] = true;
                child.path += direction[i];
                que.push(child);
            }
        }
    }
    return "unsolvable";
}

int main(){

    Puzzle puzzle;

    for(int i = 0; i < N_2D; ++i){
        cin >> puzzle.location[i];
        if(puzzle.location[i] == 0){
            // spaceの場所をセットする
            puzzle.location[i] = N_2D;
            puzzle.space = i;
        }
    }

    string ans = bfs(puzzle);
    cout << ans.size() << endl;
    
    return 0;
}