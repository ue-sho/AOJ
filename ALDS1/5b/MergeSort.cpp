/**　マージソート　**/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int cnt = 0;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1), R(n2+1);   //新しく配列分の領域が必要
                                    //他のソートアルゴリズムに比べメモリが必要になる
                                    //番兵分に一つ多くの配列が必要
    rep(i, n1)
        L[i] = A[left + i];
    rep(i, n2)
        R[i] = A[mid + i];
    
    L[n1] = INT_MAX;    //番兵
    R[n2] = INT_MAX;    //番兵
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left+1 < right){             //1つになるまで分割
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int s[500000];
    rep(i, n){
        cin >> s[i];
    }

    mergeSort(s, 0, n);

    rep(i, n){
        if(i != n-1)
            cout << s[i] << " ";
        else
            cout << s[i] << endl;
    }
    cout << cnt << endl;

    return 0;
}