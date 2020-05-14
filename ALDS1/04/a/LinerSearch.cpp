#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<int> b(n);
    for(int i = 0; i < q; ++i){
        cin >> b[i];
    }

    int cnt = 0;
    for(int i = 0; i < q; ++i){
        for(int j = 0; j < n; ++j){
            if(b[i] == a[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
