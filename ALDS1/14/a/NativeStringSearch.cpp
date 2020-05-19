#include<iostream>
using namespace std;

int main() {

    string t, p;
    cin >> t >> p;

    if(t.length() < p.length()){
        return 0;
    }

    for(int i = 0; i < t.length() - p.length() + 1; ++i){
        string str = t.substr(i, p.length());
        if(str == p){
            cout << i << endl;
        }
    }

    return 0;
} 