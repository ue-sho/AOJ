#include<iostream>
#include<vector>
using namespace std;

struct Card{
    char suit;
    int value;
};

bool is_stable_sort(const vector<Card>& stable, const vector<Card>& c, const int n){
    for(int i=0; i < n; ++i){
        if(stable[i].suit != c[i].suit){
            return false;
        }
    }
    return true;
}

void print_array(const vector<Card>& c, const int n){
    for(int i=0; i < n-1; ++i){
        if(i){
            cout << " ";
        }
        cout << c[i].suit << c[i].value;
    }
    cout << endl;
}

void bubble_sort(vector<Card>& c, const int n){
    
    for(int i=0; i < n-1; ++i){
        for(int j = n-1; j > i; --j){
            if(c[j].value < c[j-1].value){
                Card tmp = c[j-1];
                c[j-1] = c[j];
                c[j] = tmp;
            }
        }
    }
}

void selection_sort(vector<Card>& c, const int n){

    for(int i = 0; i < n; ++i){
        int minv = i;
        for(int j = i; j < n; ++j){
            if(c[minv].value > c[j].value){
                minv = j;
            }
        }
        if(minv != i){
            Card tmp = c[minv];
            c[minv] = c[i];
            c[i] = tmp;
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<Card> bubble;
    for(int i = 0; i < n; ++i){
        cin >> bubble[i].suit >> bubble[i].value;
    }
    vector<Card> insertion = bubble;

    // バブルソートは安定
    // 選択ソートは不安定
    bubble_sort(bubble, n);
    print_array(insertion, n);
    cout << "Stable" << endl;

    selection_sort(insertion, n);
    print_array(insertion, n);
    if(is_stable_sort(bubble, insertion, n)){
        cout << "Stable" << endl;
    }
    else{
        cout << "Not stable" << endl;
    }

    return 0;
}