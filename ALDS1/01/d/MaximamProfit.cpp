#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> r(n);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }

    int ans = INT_MIN;
    int min_n = r[0];
    
    // 最大と最小をその都度見ていく
    for(int i= 1; i < n; i++){
        ans = max(ans, r[i] - min_n);
        min_n = min(min_n, r[i]);
    }
    cout << ans << endl;

    return 0;
}