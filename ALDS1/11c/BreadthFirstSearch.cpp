#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define N 100
#define NIL -1
//幅優先探索
void bfs(const vector<vector<int> > &graph, int n, int starting_point){ 
    
    queue<int> q;
    vector<int> distance(n, NIL);

    q.push(starting_point);
    distance[starting_point] = 0;

    int node;
    while(!q.empty()){
        node = q.front(); q.pop();
        rep(i, graph[node].size()){
            if(distance[graph[node][i]] != NIL){
                continue; //もう探索済み
            }
            distance[graph[node][i]] = distance[node] + 1;
            q.push(graph[node][i]);
        }
    }


    rep(i, n){
        cout << i+1 << " " << distance[i] << endl;
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<int> > graph(n);
    rep(i, n){
        int k, l;
        cin >> k >> l;
        rep(j, l){
            int v;
            cin >> v;
            graph[k-1].push_back(v-1);
        }
    }

    bfs(graph, n, 0);

    return 0;
}