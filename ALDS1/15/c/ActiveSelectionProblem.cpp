#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 区間スケジューリング問題
int main(){

    int n;
    cin >> n;
    // first : 活動の終わり, second : 活動の始まり
    vector<pair<int, int>> activity(n);
    for(int i = 0; i < n; ++i){
        cin >> activity[i].second >> activity[i].first;
    }
    // 終わりが早い順に並べる
    sort(activity.begin(), activity.end());

    int time = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(activity[i].second > time){
            time = activity[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}