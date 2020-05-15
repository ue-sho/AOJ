#include<iostream>
#include<vector>
using namespace std;
                     
void counting_sort(const vector<int> &A, vector<int> &B, const int n, const int max_value){
    
    vector<int> C(max_value + 1);

    // A[i] の出現数を記録する
    for(int i = 0; i < n; ++i) {
        C[A[i]]++;
    }

    // 累積和
    // C[i] が B[i] に入れる時のインデックスになる
    for(int i = 1; i <= max_value; ++i){
        C[i] += C[i-1];
    }

    for(int i = n-1; i >= 0; --i){
        // 1-indexなので先にマイナス1する
        int idx = --C[A[i]];
        B[idx] = A[i];
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    counting_sort(a, b, n, 10000);
    
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;

    return 0;
}