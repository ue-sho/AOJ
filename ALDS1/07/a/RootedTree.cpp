#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

struct Edge{
    int parent;
    int depth;
};

int main() {

    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<Edge> info(n);
    rep(i, n){
        int id, m;
        cin >> id >> m;
        rep(j, m){
            int x;
            cin >> x;
            v[id].push_back(x);
            info[x] = (Edge){id, info[id].depth + 1};
            rep(k, v[x].size()){
                info[v[x][k]].depth = info[x].depth + 1;
            }
        }
    }

    rep(i, n){
        string s;
        if(info[i].parent == 0 && info[i].depth == 0){
            s = "root, [";
            info[i].parent = -1;
        }
        else if(v[i].size() == 0){
            s = "leaf, [";
        }
        else{
            s = "internal node, [";
        }

        cout << "node " << i << ": parent = " << info[i].parent 
            << ", depth = " << info[i].depth << ", " << s;

        if(v[i].size() == 0){
            cout << "]\n";
        }
        rep(j, v[i].size()){
            if(j != v[i].size()-1){
                cout << v[i][j] << ", ";
            }
            else{
                cout << v[i][j] << "]" << endl;
            }
        }
    }
    return 0;
}
