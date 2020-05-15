#include<iostream>
#include<queue>
using namespace std;

int main() {

    priority_queue<int> que;
    while(true){
        string command;
        cin >> command;
        if(command == "insert"){
            int num;
            cin >> num;
            que.push(num);
        }
        else if(command == "extract"){
            cout << que.top() << endl;
            que.pop();
        }
        else if(command == "end"){
            break;
        }
    }
    return 0;
}