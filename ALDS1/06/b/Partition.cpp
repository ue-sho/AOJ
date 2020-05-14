/*** パーテーション ***/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int partition(int A[], int p, int r){
    int x = A[r];
    int i  = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;

    return i+1;
}

int main()
{
    int n;
    cin >> n;
    int a[100000];
    rep(i, n){
        cin >> a[i];
    }

    int p = partition(a, 0, n-1);

    rep(i, n){
        if(p == i){
            cout << "[" << a[i] << "] ";
        }
        else if(i == n-1){
            cout << a[i] << endl;
        }
        else{
            cout << a[i] << " ";
        }
    }

    return 0;
}