#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

#define MAX 1000
int lcs(string x, string y){
    //最長共通部分列問題
    int dp[MAX+1][MAX+1];
    int ret = 0;
    int n = x.size();
    int m = y.size();
    x = ' ' + x; //x[0]をつくる
    y = ' ' + y; //y[0]をつくる

    rep(i, n) dp[i][0] = 0;
    rep(j, m) dp[0][j] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i] == y[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int main() {

    int n;
    cin >> n;

    rep(i, n){
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }

    return 0;
}