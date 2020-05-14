#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main() {

    int n;
    cin >> n;
    int mat[100][100] = {};
    rep(i, n){
        int k, l;
        cin >> k >> l;
        rep(j, l){
            int v;
            cin >> v;
            mat[k-1][v-1] = 1;
        }
    }

    rep(i, n){
        rep(j, n){
            cout << mat[i][j];
            if(j == n-1){
                cout << "\n";
            }
            else{
                cout << ' ';
            }
        }
    }


    return 0;
}