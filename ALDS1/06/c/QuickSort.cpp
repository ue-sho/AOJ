#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using Card = pair<char, int>;   // first : カードの種類, second : カード番号

int my_partition(vector<Card>& A, const int begin, const int end){
    int x = A[end].second;
    int idx  = begin -1;
    for(int j = begin; j <= end; j++){
        if(A[j].second <= x){
            swap(A[++idx], A[j]);
        }
    }
    return idx;
}

void quick_sort(vector<Card>& A, int begin, int end){
    if(begin < end){
        int base = my_partition(A, begin, end);
        quick_sort(A, begin, base - 1);
        quick_sort(A, base + 1, end);
    }
}

int merge(vector<Card>& A, const int left, const int mid, const int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Card> L(n1+1), R(n2+1);  //新しく配列分の領域が必要
                                    //他のソートアルゴリズムに比べメモリが必要になる
                                    //番兵分に一つ多くの要素が必要
    for(int i = 0; i < n1; ++i){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; ++i){
        R[i] = A[mid + i];
    }

    L[n1] = {' ', INT_MAX};    //番兵
    R[n2] = {' ', INT_MAX};    //番兵
    
    int i = 0, j = 0, cnt = 0;
    for(int k = left; k < right; ++k){
        cnt++;
        if(L[i].second <= R[j].second){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
    return cnt;
}

// 戻り値は比較した回数
int merge_sort(vector<Card>& A, const int left, const int right){
    int cnt = 0;
    if(left+1 < right){             //1つになるまで分割
        int mid = (left + right)/2;
        cnt += merge_sort(A, left, mid);
        cnt += merge_sort(A, mid, right);
        cnt += merge(A, left, mid, right);
    }
    return cnt;
}

int main(){

    int n;
    cin >> n;
    vector<Card> quick(n);
    for(int i = 0; i < n; ++i){
        cin >> quick[i].first >> quick[i].second;
    }
    vector<Card> merge = quick;

    quick_sort(quick, 0, n-1);
    merge_sort(merge, 0, n);

    if(merge == quick){
        cout << "Stable" << endl;
    }
    else{
        cout << "Not stable" << endl;
    }
    for(int i = 0; i < n; ++i){
        cout << quick[i].first << " " << quick[i].second << endl;
    }

    return 0;
}