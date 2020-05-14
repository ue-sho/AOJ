#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

/*** 解けなかった 再帰・分割統括法 ***/
bool solve(int idx, int serch, int a[], int size){
    
    if(serch == 0){ //求める値になったら終わり(成功)
        return true;
    }
    else if(serch < 0){
        return false;
    }

    if(idx >= size){ //配列の最後まで行ったら終わり(失敗)
        return false;
    }
            //調べる頂点を変える             //計算　どんどん減算していく
    return solve(idx+1, serch, a, size) || solve(idx+1, serch-a[idx], a, size);
}

int main()
{
    int n;
    cin >> n;
    int a[20];
    rep(i, n){
        cin >> a[i];
    }

    int q;
    cin >> q;
    int m;
    rep(i, q){
        cin >> m;
        if(solve(0, m, a, n)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}