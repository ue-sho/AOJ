#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int n;
    cin >> n;
    int a[100000];
    rep(i, n){
        cin >> a[i];
    }
    int q;
    cin >> q;
    int b[100000];
    rep(i, q){
        cin >> b[i];
    }

    int cnt = 0;
    rep(i, q){
        rep(j, n){
            if(b[i] == a[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
