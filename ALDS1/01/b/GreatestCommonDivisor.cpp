#include<iostream>
using namespace std;

//ユークリッドの互除法
template <class T>
T gcd(T a, T b) {
    if(b == 0){
        return a;
    }
    gcd(b, a % b);
}

int main(){

    int x, y;
    cin >> x >> y;

    cout << gcd(x, y) << endl;

    return 0;
}