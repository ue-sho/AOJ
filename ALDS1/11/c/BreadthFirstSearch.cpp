#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//幅優先探索
void bfs(const vector<vector<int>>& graph, const int n, const int starting_point){ 
    
    queue<int> que;
    que.push(starting_point);

    constexpr int NIL = -1;
    vector<int> distance(n, NIL);
    distance[starting_point] = 0;

    while(!que.empty()){
        int node = que.front(); que.pop();
        for(auto next : graph[node]){
            if(distance[next] != NIL){
                continue; //もう探索済み
            }
            distance[next] = distance[node] + 1;
            que.push(next);
        }
    }

    for(int i = 0; i < n; ++i){
        cout << i+1 << " " << distance[i] << endl;
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; ++i){
        int k, l;
        cin >> k >> l;
        for(int j = 0; j < l; ++j){
            int v;
            cin >> v;
            graph[k-1].push_back(v-1);
        }
    }

    bfs(graph, n, 0);

    return 0;
}