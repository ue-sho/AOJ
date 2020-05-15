#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i){
        cout << "node " << i << ": ";
        cout << "key = " << a[i] << ", ";
        if(i > 1){
            cout << "parent key = " << a[i / 2] << ", ";
        }
        if(i * 2 <= n){
            cout << "left key = " << a[i * 2] << ", ";
        }
        if(i*2 + 1 <= n){
            cout << "right key = " << a[i * 2 + 1] << ", ";
        }
        cout << endl;
    }

    return 0;
}