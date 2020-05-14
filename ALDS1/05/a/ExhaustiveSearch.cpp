#include<iostream>
#include<vector>
using namespace std;

/*** 再帰・分割統括法 ***/
bool exhaustive_search(const int idx, const int key, const vector<int>& a, const int size){
    
    if(key == 0){ // 求める値になったら終わり(成功)
        return true;
    }

    if(idx >= size){ // 配列の最後まで行ったら終わり(失敗)
        return false;
    }
                // 調べる頂点を変える                       // 計算　keyをどんどん減算していく
    return exhaustive_search(idx+1, key, a, size) || exhaustive_search(idx+1, key-a[idx], a, size);
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int key;
        cin >> key;
        if(exhaustive_search(0, key, a, n)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}