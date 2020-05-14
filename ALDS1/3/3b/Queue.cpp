/*キュー*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

struct Process{
    string name;
    int time;
};

class Queue{
    int head;
    int tail;
    Process a[100000];
    int n;
public:
    Queue(int num) {
        head = 0;
        tail=0;
        n = num;
    }
    bool isEmpty(){
        if(head == tail){
            return true;
        }
        else{
            return false;
        }
    }
    void enq(Process p){  
        if(tail == n+1){
            tail = 0;
        }   
        a[tail++] = p;
    }

    Process deq(){
        if(head == n+1){
            head = 0;
        }
        return a[head++];
    }
};

int main()
{
    int n, t;
    cin >> n >> t;

    Process p;
    Queue q(n);
    rep(i, n){
        cin >> p.name >> p.time;
        q.enq(p);
    }

    int now_time = 0;
    while(!q.isEmpty()){
        Process tmp = q.deq();
        if(tmp.time > t){
            tmp.time -= t;
            q.enq(tmp);
            now_time += t;
        }
        else{
            now_time += tmp.time;
            cout << tmp.name << " " << now_time << "\n";
        }
    }

    return 0;
}