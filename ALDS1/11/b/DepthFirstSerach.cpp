#include<iostream>
#include<vector>
using namespace std;

// 深さ優先探索
void dfs(const int node, const vector<vector<int>>& graph, 
            vector<pair<int, int>>& time, vector<int>& discover){
    static int cnt = 1;
    discover[node] = true;
    time[node].first = cnt++; //発見
    for(auto next : graph[node]){
        if(discover[next]){
            continue;   // 前回(親)と同じだったら次へ
        }
        dfs(next, graph, time, discover);
    }
    time[node].second = cnt++; // 完了
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

    // first : 発見時刻, second : 完了時刻
    vector<pair<int, int>> time(n);
    vector<int> discover(n);   // 発見されているかどうか
    for(int i = 0; i < n; ++i){
        if(discover[i]){
            continue;
        }
        dfs(i, graph, time, discover);
    }

    for(int i = 0; i < n; ++i){
        cout << i + 1 << " " << time[i].first << " " << time[i].second << endl;
    }

    return 0;
}