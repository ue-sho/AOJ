#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    vector<string> ch(n);
    rep(i, n){
        cin >> s[i] >> ch[i];
    }

    vector<string> dic;
    rep(i, n){
        if(s[i] == "insert"){
            dic.push_back(ch[i]);
        }
        else{
            bool flag = false;
            rep(j, dic.size()){
                if(ch[i] == dic[j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
    }
    return 0;
}
