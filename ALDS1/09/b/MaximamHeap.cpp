#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 値が大きいものを親にしていく
void max_heapify(vector<int>& A, const int idx, const int n){
    int left = idx * 2;
    int right = idx * 2 + 1;

   // 左の子、自分、右の子で値が最大のノードを選ぶ
    int largest = idx;
    if(left <= n && A[left] > A[idx]){
        largest = left;
    }
    if(right <= n && A[right] > A[largest]){
        largest = right;
    }
    
    if(largest != idx){  // i の子の方が値が大きい場合
        swap(A[largest], A[idx]);
        max_heapify(A, largest, n); // 再帰的に呼び出し
    }
}

void build_max_heap(vector<int>& A, const int n){
    for(int i = n / 2; i >= 1; --i){
        max_heapify(A, i, n);
    }
}

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    build_max_heap(a, n);

    for(int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}