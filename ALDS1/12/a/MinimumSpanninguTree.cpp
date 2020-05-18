#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int to;
    int cost;
};

int prim(vector<vector<edge>>& edges, int V) {
    int res = 0;
    using P = pair<int, int>;
    vector<bool> used(V, false);
    // P -> first : コスト, second : 行先
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, 0);
    // コストが小さい順に出しいく
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        if(used[p.second]){
            continue;
        }
        used[p.second] = true;
        res += p.first;
        for(const auto e : edges[p.second]){
            if(!used[e.to]){
                que.emplace(e.cost, e.to);
            }
        }
    }
    return res;
}

int main() {

    int n;
    cin >> n;
    vector<vector<edge>> edges(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int a;
            cin >> a;
            if(a != -1){
                edges[i].emplace_back((edge){j, a});
            }
        }
    }

    cout << prim(edges, n) << endl;

    return 0;
} 