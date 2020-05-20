#include<iostream>
#include<queue>
#include<set>
#include<string>

using namespace std;

vector<int> bfs(int root, const vector<vector<int>>& graph){
    queue<int> que;
    vector<int> distance(52);
    que.push(root);
    distance[root] = 0;
    while(!que.empty()){
        int parent = que.front(); que.pop();
        for(const auto child : graph[parent]){
            distance[child] = distance[parent] + 1;
            que.push(child);
        }
    }
    return distance;
}

int main(){
    
    string s; 
    cin >> s;

    set<char> st;
    vector<int> cnt(26);
    for(const char c : s) {
        cnt[c-'a']++;
        st.insert(c);
    }

    if(st.size() == 1){
        // すべて同じ文字なら長さを出力
        cout << s.size() << endl;
        return 0;
    }

    using P = pair<int, int>;
    int id = 0;
    vector<int> mark(26);   // 出現した文字の目印
    priority_queue<P, vector<P>, greater<P>> pq;
    for(const char c : st){
        mark[c-'a'] = id;
        pq.emplace(cnt[c-'a'], id++);
    }

    // 全部違う文字だった場合 -> MAX 2 * 26
    vector<vector<int>> graph(52);  
    while(pq.size() > 1){
        P x = pq.top(); pq.pop();
        P y = pq.top(); pq.pop();
        pq.push(make_pair(x.first + y.first, id));
        graph[id].push_back(x.second);
        graph[id].push_back(y.second);
        id++;
    }
    
    vector<int> distance = bfs(id-1, graph);

    int ans = 0;
    for(int i = 0; i < s.length(); ++i){
        ans += distance[mark[s[i]-'a']];
    }
    cout << ans << endl;
}