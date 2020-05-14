#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int f[45];

void FibonacciInit(){

    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=44; i++){
        f[i] = f[i-1] + f[i-2];
    }
}

int main() {

    int n;
    cin >> n;

    FibonacciInit();

    cout << f[n] << endl;

    return 0;
}