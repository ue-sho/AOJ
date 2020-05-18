#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

constexpr int MAX_WEIGHT = 10000; // 重さの最大値

int calc_cost(vector<int>& weight, int n, int min_weight){
    int cost = 0;

    vector<int> sorted_wight = weight;
    sort(sorted_wight.begin(), sorted_wight.end());   // ソートされた状態を作る

    vector<int> idx_record(MAX_WEIGHT + 1);
    for(int i = 0; i < n; ++i){
        // ソート済みの要素のインデックスがどこにあるか記録
        idx_record[sorted_wight[i]] = i;
    }

    vector<bool> verified(n, false);  // コストを確認済みかどうか
    for(int i = 0; i < n; ++i){
        if(verified[i]){
            continue;   // 確認済みなら次へ
        }
        int cur = i;        // 自分の現在地（カーソル）
        int sum_in_loop = 0;          // ループ内の重さ合計  
        int min_in_loop = MAX_WEIGHT; // ループ内での重さ最小値
        int count = 0;      // 交換回数
        while(true){
            verified[cur] = true;
            count++;
            int current_weight = weight[cur];    // 
            min_in_loop = min(min_in_loop, current_weight);
            sum_in_loop += current_weight;
            cur = idx_record[current_weight];
            if(verified[cur]){
                break;  // 一周回ったら終わり
            }
        }
        // sum_in_loop に min_in_loop が含まれている. 自分は入れ替える必要ない. なので count - 2 
        int not_borrow_weight = sum_in_loop + (count - 2) * min_in_loop;
        
        // min_weight を取ってくるのに 1回 必要なので count + 1
        int borrow_min_weight = min_in_loop + sum_in_loop + (count + 1) * min_weight;
        
        cost += min(not_borrow_weight, borrow_min_weight);
    }
    return cost;
}

int main(){

    int n;
    cin >> n;
    
    int min_weight = MAX_WEIGHT; // 荷物の中での重さ最小値
    vector<int> weight(n);
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
        min_weight = min(min_weight, weight[i]);
    }

    int cost = calc_cost(weight, n, min_weight);

    cout << cost << endl;

    return 0;
}