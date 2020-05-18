#include<iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    constexpr int MAX = 100;
    int mat[MAX][MAX] = {};
    for(int i = 0; i < n; ++i){
        int k, l;
        cin >> k >> l;
        for(int j = 0; j < l; ++j){
            int v;
            cin >> v;
            mat[k-1][v-1] = 1;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j){
                cout << " ";
            }
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}