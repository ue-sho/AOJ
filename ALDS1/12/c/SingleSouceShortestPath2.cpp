#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct edge {
    int to;
    int cost;
};

// SingleSourcePath1 と全く同じ実装　本当は1で優先度付きキューは使わない
void dijkstra(const vector<vector<edge>>& edges, vector<int>& distance, int start_point) {
    distance[start_point] = 0;

    using P = pair<int, int>;
    // P -> first : 最短距離, second : 頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, start_point);

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int next = p.second;
        if (distance[next] < p.first){
            continue;
        }
        for(const auto e : edges[p.second]){
            if(distance[e.to] > distance[next] + e.cost){
                distance[e.to] = distance[next] + e.cost;
                que.emplace(distance[e.to], e.to);
            }
        }
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<edge>> edges(n);
    for(int i = 0; i < n; ++i){
        int u, k;       // u:頂点, k:隣接リストの個数
        cin >> u >> k;
        for(int j = 0; j < k; ++j){
            int v, c;   // v:隣接リストの番号, c:重み
            cin >> v >> c;
            edges[u].emplace_back((edge){v, c});
        }
    }

    vector<int> distance(n, INT_MAX);
    dijkstra(edges, distance, 0);

    for(int i = 0; i < n; ++i){
        cout << i << " " << distance[i] << endl;
    }

    return 0;
} 