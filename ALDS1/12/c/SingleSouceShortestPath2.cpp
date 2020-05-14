#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 1 << 21

//ダイクストラ法 優先度付きキューを用いた高速化
void dijkstra(vector<vector<pair<int, int> > > &graph, int n){

    priority_queue<pair<int, int> > PQ;
    vector<int> color(n, WHITE);
    vector<int> cost(n, INF);

    PQ.push(make_pair(0, 0));
    cost[0] = 0;
    color[0] = GRAY;

    while(!PQ.empty()){
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;    //現在地

        color[u] = BLACK;

        if(cost[u] < f.first * (-1)) continue;

        rep(i, graph[u].size()){
            int v = graph[u][i].first;
            
            if(color[v] == BLACK) continue;

            if(cost[v] > cost[u] + graph[u][i].second){
                cost[v] = cost[u] + graph[u][i].second;
                PQ.push(make_pair(cost[v]*(-1), v));
                color[v] = GRAY;
            }
        }
    }

    rep(i, n){
        cout << i << " " << cost[i] << endl;
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<pair<int, int> > > graph(n);
    int k, c, u , v;
    rep(i, n){
        cin >> u >> k; //u 頂点  k 隣接リストの個数
        rep(j, k){
            cin >> v >> c;      //隣接リストの番号 //隣接リストの重み
            graph[i].push_back(make_pair(v, c));
        }
    }

    dijkstra(graph, n);

    return 0;
} 