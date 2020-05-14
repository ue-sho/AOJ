#include<iostream>
#include<stack>
using namespace std;

int main(){
    
    string str; //数字が二桁以上もあるのでstring型
    stack<int> st;
    while(cin >> str){
        if(str == "+"){
            int x = st.top(); 
            st.pop();
            int y = st.top(); 
            st.pop();
            st.push(x + y);
        }
        else if(str == "-"){
            int x = st.top(); 
            st.pop();
            int y = st.top(); 
            st.pop();
            st.push(y - x);
        }
        else if(str == "*"){
            int x = st.top(); 
            st.pop();
            int y = st.top(); 
            st.pop();
            st.push(x * y);
        }
        else{
            st.push(stoi(str));
        }
    }
    cout << st.top() << endl;
    
    return 0;
}