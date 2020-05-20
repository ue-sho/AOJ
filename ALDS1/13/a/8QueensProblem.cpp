#include<iostream>
#include<vector>
using namespace std;

class Queen{
    static const int N = 8;
    vector<bool> horizontal, vertical;
    vector<bool> right_angled, left_angled;
    vector<pair<int, int>> position;
public:
    Queen() : horizontal(N), vertical(N), right_angled(2*N-1), left_angled(2*N-1) {}

    void queen_set(int x, int y) {
        horizontal[y] = vertical[x] = right_angled[x + y] = left_angled[x - y + N - 1] = true;
        position.emplace_back(x, y);
    }

    void queen_unset(int x, int y) {
        horizontal[y] = vertical[x] = right_angled[x + y] = left_angled[x - y + N - 1] = false;
        position.pop_back();
    }

    bool is_used(int x, int y) {
        return (horizontal[y] || vertical[x] || right_angled[x + y] || left_angled[x - y + N - 1]);
    }

    void print() {
        vector<vector<bool>> placement(N, vector<bool>(N));

        for(auto p : position){
            placement[p.second][p.first] = true;
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++){
                cout << (placement[y][x] ? 'Q' : '.');
            }
            cout << endl;
        }
    }

    void dfs(int y){
        if(y >= N){
            print();
            return;
        }

        if(horizontal[y]){
            dfs(y + 1);
        }
        else{
            for (int x = 0; x < N; x++){
                if (!is_used(x, y)) {
                    queen_set(x, y);
                    dfs(y + 1);
                    queen_unset(x, y);
                }
            }
        }
    }

};

int main(){

    int k;
    cin >> k;

    Queen queen;
    for(int i = 0; i < k; ++i){
        int r, c;
        cin >> r >> c;
        queen.queen_set(c, r);
    }

    queen.dfs(0);

    return 0;
} 