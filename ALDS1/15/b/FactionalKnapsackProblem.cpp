#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
    int N, W; 
    cin >> N >> W;

    vector<pair<double, pair<int, int>>> items;
    for(int i = 0; i < N; ++i){
        int v, w;
        cin >> v >> w;
        items.emplace_back((double)v / (double)w, make_pair(v, w));
    }
    // 重さに対しての価値が高い順に並び変える
    sort(items.rbegin(), items.rend());

    double ans = 0;
    int weight = 0;
    for(const auto item : items){
        if(weight + item.second.second > W){
            int dif = W - weight;
            ans += (double) dif * item.first;
            weight += dif;
            break;
        } 
        else {
            ans += item.second.first;       // v
            weight += item.second.second;   // w
        }
    }

    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}