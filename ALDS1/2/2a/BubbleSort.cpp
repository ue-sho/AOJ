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

int bubble_sort(vector<int>& a, int n){
    int cnt = 0;
    for(int i=0; i< n-1; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] < a[j-1]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                cnt++;
            }
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

    int cnt = bubble_sort(a, n);
    
    print_array(a, n);
    cout << cnt << endl;
    
    return 0;
}