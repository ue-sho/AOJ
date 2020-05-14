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

void insert_sort(vector<int>& a, int n){
    int tmp;
    for(int i = 1; i < n; i++){
        tmp = a[i];
        for(int j = i-1; j >= 0; j--){
            if(tmp < a[j]){
                a[j+1] = a[j];
                a[j] = tmp;
            }
            else{
                break;
            }
        }
        print_array(a, n);
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    print_array(a, n);
    insert_sort(a, n);

    return 0;
}