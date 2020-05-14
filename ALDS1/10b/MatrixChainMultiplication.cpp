/*   分かっていない   */
 
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define MAX 100
int main() {

    int n;
    cin >> n;
    int p[MAX+1], m[MAX+1][MAX+1];
    for(int i=1; i<=n; i++){
        cin >> p[i-1] >> p[i];
    }

    for(int i=1; i<=n; i++){
        m[i][i] = 0;    //初期化
    }

    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;     //INFいれる
            for(int k=i; k<=j-1; k++){
                m[i][j] = min(m[i][j], ( m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j] ) );
            }
        }
    }

    cout << m[1][n] << endl;
   
    return 0;
}