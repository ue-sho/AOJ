#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 戻り値は交換が行われた回数
 */
int insertion_sort(vector<int>& a, const int n, const int dis){
    int cnt = 0;
    for(int i = dis; i < n; ++i){
        int tmp = a[i];
        int j = i - dis;    // 距離がdis離れている所のインデックス
        while(j >= 0 && a[j] > tmp){
            // 値が大きいものは後ろに持っていく
            a[j + dis] = a[j];
            j -= dis;
            cnt++;
        }
        a[j + dis] = tmp;
    }
    return cnt;
}

int shell_sort(vector<int>& a, const int n, vector<int>& distance){
    
    // {1, 4, 7, ....} と n を超えるまで格納する
    for(int i = 1; i <= n; i = 3*i + 1){
        distance.push_back(i);
    }
    reverse(distance.begin(), distance.end());
    
    int cnt = 0;
    // だんだん交換の距離を狭めていく
    for(int i = 0; i < distance.size(); i++){
        cnt += insertion_sort(a, n, distance[i]);
    }
    return cnt;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> distance;
    int cnt = shell_sort(a, n, distance);

    // シェルソートに使った幅の数と値
    int size = distance.size();
    cout << size << endl;
    for(int i = 0; i < size; ++i){
        if(i){
            cout << " ";
        }
        cout<< distance[i];
    }
    cout << endl;

    // 交換が行われた回数
    cout << cnt << "\n";

    // ソートされているかの確認
    for(int i = 0; i < n; ++i){
        cout << a[i] << endl;
    }

    return 0;
}
