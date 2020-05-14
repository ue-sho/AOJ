#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// ベルトコンベアから順番に流れてくるで、それをトラックに積む
// (連続する0個以上の荷物を積むことができる)
bool stack_baggage(const vector<int>& weight, const int n, const int k, const int p){
    vector<int> track(k);
    int idx = 0;
    for(int i = 0; i < n; ++i){
        if(track[idx] + weight[i] > p){
            // 重量オーバーなので次のトラック
            if(++idx >= k){
                // 次のトラックがない
                return false;
            }
            else{
                // もう一度確認
                if(track[idx] + weight[i] > p){
                    return false;
                }
                track[idx] += weight[i];
            }
        }
        else{
            track[idx] += weight[i];
        }
    }
    return true;
}

int binary_search(const vector<int>& weight, const int n, const int k){

    int left = 0, right = INT_MAX;
    while(abs(left - right) > 1){
        int mid = (left + right) / 2;

        if(stack_baggage(weight, n, k, mid)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return right;
}

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> weight(n);
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
    }

    cout << binary_search(weight, n, k) << endl;

    return 0;
}