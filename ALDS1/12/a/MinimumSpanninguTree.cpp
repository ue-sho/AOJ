#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 1 << 21

//プリムのアルゴリズム
int prim(vector<vector<int> > &graph, int n){

    vector<int> parent(n, NIL);
    vector<int> cost(n, INF);
    vector<int> color(n, WHITE);

    cost[0] = 0;
    while(1){
        int minv = INF;
        int u = NIL;    //現在地
        rep(i, n){
            if(cost[i] < minv && color[i] != BLACK){
                minv = cost[i];
                u = i;
            }
        }
        if(u == NIL) break;

        color[u] = BLACK;
        rep(j, n){
            if(color[j] != BLACK && graph[u][j] != NIL){
                if(cost[j] > graph[u][j]){
                    cost[j] = graph[u][j];
                    parent[j] = u;
                    color[j] = GRAY;
                }
            }
        }
    }

    int sum = 0;
    rep(i, n){
        if(parent[i] != NIL){
            sum += graph[i][parent[i]];
        }
    }
    return sum;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int> > graph(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            cin >> graph[i][j];
        }
    }

    cout << prim(graph, n) << endl;

    return 0;
} 