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
    int b[50000];
    rep(i, q){
        cin >> b[i];
    }

    int cnt = 0;
    rep(i, q){
        int left = 0;
        int right = n-1;
        while(left <= right){
            int center = (left + right) / 2;
            if(a[center] == b[i]){
                cnt++;
                break;
            }
            else if(a[center] > b[i]){
                right = center - 1;
            }
            else{
                left = center + 1;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
