#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

    int n;
    cin >> n;

    map<string, bool> dictionary;
    for(int i = 0; i < n; ++i){
        string com, x;
        cin >> com >> x;
        if(com == "insert"){
            dictionary[x] = true;
        }
        else if(com == "find"){
            if(dictionary.find(x) != dictionary.end()){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
