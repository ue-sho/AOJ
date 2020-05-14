#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define MAX 100000
#define NIL -1

void dfs(int start_point, int id, vector<int> *graph, int *color, int n){
    
    stack<int> S;
    S.push(start_point);
    color[start_point] = id;

    while(!S.empty()){
        int node = S.top(); S.pop();
        rep(i, graph[node].size()){
            int v = graph[node][i];
            if(color[v] == NIL){
                color[v] = id;
                S.push(v);
            }
        }
    }
}

void assignColor(vector<int> *graph, int *color, int n){
    int id = 1;
    rep(i, n){
        if(color[i] == NIL){
            dfs(i, id++, graph, color, n);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> graph[MAX];
    int color[MAX];
    rep(i, n){
        color[i] = NIL;
    }

    rep(i, m){
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    assignColor(graph, color, n);

    int q;
    cin >> q;
    rep(i, q){
        int x, y;
        cin >> x >> y;
        if(color[x] == color[y]){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

    return 0;
}