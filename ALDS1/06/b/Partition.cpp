#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& A, const int begin, const int end){
    int x = A[end];         // 基準
    int idx  = begin - 1;   // 基準に対しての大小の境となる場所 
    for(int j = begin; j <= end; j++){
        if(A[j] <= x){
            swap(A[++idx], A[j]);
        }
    }
    return idx;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int p = partition(a, 0, n-1);

    for(int i = 0; i < n; ++i){
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