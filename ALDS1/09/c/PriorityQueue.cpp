#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define MAX 2000001

int parent(int i){
    return i/2;
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2 + 1;
}

void maxHeapify(int A[], int i, int n){
    int l = left(i);
    int r = right(i);
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    int largest;
    if(l <= n && A[l] > A[i])
        largest = l;
    else 
        largest = i;
    
    if(r <= n && A[r] > A[largest])
        largest = r;

    if(largest != i){  // i の子の方が値が大きい場合
        swap(A[i], A[largest]);
        maxHeapify(A, largest, n); // 再帰的に呼び出し
    }
}

void insert(int num, int A[], int &n){
    A[++n] = num;
    for(int i=n; i>1; i/=2){
        if(A[i] > A[i/2]){
            swap(A[i], A[i/2]);
        }
    }
}

int extract(int A[], int &n){
    if(n < 1){
        return -INT_MAX;
    }
    int tmp = A[1];
    swap(A[1], A[n]);
    n--;
    maxHeapify(A, 1, n);
    
    return tmp;
}

int main() {

    int a[MAX];
    int n = 0;
    
    while(1){
        string command;
        cin >> command;
        if(command == "insert"){
            int num;
            cin >> num;
            insert(num, a, n);
        }
        else if(command == "extract"){
            cout << extract(a, n) << endl;
        }
        else if(command == "end"){
            break;
        }
    }
    return 0;
}