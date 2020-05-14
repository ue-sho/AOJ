/*計数ソート*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

int C[10001] = {};
                                //Bの値が書き換わるように参照渡し
void CountingSort(vector<int> &A, vector<int> &B, int k){
    
    /* C[i] に i の出現数を記録する */
    for(int i = 0; i < k; i++) {
        C[A[i]]++;
    }

    /* C[i] に i 以下の数の出現数を記録する*/
    for(int i = 1; i <= 10000; i++){
        C[i] = C[i] + C[i-1];
    }

    for(int i = k-1; i >= 0; i--){
        B[--C[A[i]]] = A[i];
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n){
        cin >> a[i];
    }

    CountingSort(a, b, n);
    
    rep(i, n){
        if(i!=n-1){
            cout << b[i] << " ";
        }
        else{
            cout << b[i] << endl;
        }
    }

    return 0;
}