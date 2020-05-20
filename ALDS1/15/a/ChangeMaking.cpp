#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    int ans = 0;
    const int coin[] = {25, 10, 5, 1};
    // 大きいコインからやるだけ
    for(int i = 0; i < 4; ++i){
        if(coin[i] <= n){
            ans += n / coin[i];
            n = n % coin[i];
        }
    }
    cout << ans << endl;

    return 0;
}