#include<iostream>
#include<list>
using namespace std;

int main(){

    int n;
    cin >> n;

    list<int> ls;
    for(int i = 0; i < n; ++i){
        string com;
        cin >> com;
        if(com == "insert"){
            int x;
            cin >> x; 
            ls.push_front(x);
        }
        else if(com == "delete"){
            int x;
            cin >> x;
            for(auto it = ls.begin(); it != ls.end(); ++it){
                if(*it == x){
                    ls.erase(it);
                    break;
                }
            }
        }
        else if(com == "deleteFirst"){
            ls.pop_front();
        }
        else if(com == "deleteLast"){
            ls.pop_back();
        }
    }

    for(const auto x : ls){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
