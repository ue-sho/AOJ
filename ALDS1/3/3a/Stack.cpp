/*スタック*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

class Stack{
    int idx = 0;
    int a[100] = {0};
public:
    char c[100000];
    void push(int n){       
        a[idx++] = n;
    }

    int pop(){
        return a[--idx];
    }
};

int main()
{
    Stack s;
    while(scanf("%s", s.c) != EOF){
        if(s.c[0] == '+'){
            int tmp = s.pop() + s.pop();
            s.push(tmp);
        }
        else if(s.c[0] == '-'){
            int tmp1 = s.pop();
            int tmp2 = s.pop();
            s.push(tmp2-tmp1);
        }
        else if(s.c[0] == '*'){
            int tmp = s.pop() * s.pop();
            s.push(tmp);
        }
        else{
            s.push(atoi(s.c));
        }
    }
    
    cout << s.pop() << endl;
    
    return 0;
}