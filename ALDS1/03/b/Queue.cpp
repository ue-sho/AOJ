#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    queue<pair<string, int>> que;
    for(int i = 0; i < n; ++i){
        string name;
        int time;
        cin >> name >> time;
        que.push({name, time});
    }
    
    int now_time = 0;
    while(!que.empty()){
        string name = que.front().first;
        int time = que.front().second;
        que.pop();
        
        if(time > t){
            time -= t;
            now_time += t;
            que.push({name, time});
        }
        else{
            now_time += time;
            cout << name << " " << now_time << endl;
        }
    }

    return 0;
}