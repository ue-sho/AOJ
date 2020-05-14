#include<iostream>
#include<vector>
using namespace std;

void print_array(const vector<int>& a, int n){
    for(int i = 0; i < n; i++){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

int selection_sort(vector<int>& a, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int minv = i;
        for(int j=i; j<n; ++j){
            // 一番小さいやつを選ぶ
            if(a[minv] > a[j]){
                minv = j;
            }
        }
        if(minv != i){
            cnt++;
            int tmp = a[minv];
            a[minv] = a[i];
            a[i] = tmp;
        }
    }
    return cnt;
}


int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cnt = selection_sort(a, n);
    
    print_array(a, n);
    cout << cnt << endl;

    return 0;
}