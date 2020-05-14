#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    int q;
    cin >> q;
    vector<int> t(n);
    for(int i = 0; i < q; ++i){
        cin >> t[i];
    }

    int cnt = 0;
    for(int i = 0; i < q; ++i){
        if(binary_search(s.begin(), s.end(), t[i])){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
