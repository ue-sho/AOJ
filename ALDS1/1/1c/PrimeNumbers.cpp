#include<iostream>
#include<vector>
using namespace std;

// 素数判定
bool is_prime(int x) {
    if(x < 2){
        return false;
    }
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main(){

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(is_prime(a)){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}