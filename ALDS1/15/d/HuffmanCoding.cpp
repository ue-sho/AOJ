#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    
    string s;
    cin>>s;

    if(s == string(s.size(), s[0])){
        // すべて同じ文字なら長さを出力
        cout<< s.size() <<endl;
        return 0;
    }

    vector<int> cnt(26);
    for(char c : s){
        cnt[c-'a']++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < 26; ++i){
        if(cnt[i] > 0){
            pq.emplace(cnt[i]);
        }
    }

    int ans = 0;
    while(pq.size() > 1){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        ans += x + y;
        pq.emplace(x + y);
    }
    cout << ans << endl;

    return 0;
}