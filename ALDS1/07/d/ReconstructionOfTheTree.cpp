#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reconstruction(const vector<int>& pre, const vector<int>& in, 
                    vector<int>& post, int left, int right){
    if(left >= right){
        return;
    }
    static int position = 0;    // 再帰中でも順番に取り出すためにstatic
    int value = pre[position++];
    int middle = distance(in.begin(), find(in.begin(), in.end(), value));
    reconstruction(pre, in, post, left, middle);
    reconstruction(pre, in, post, middle+1, right);
    post.push_back(value);  // 後行順巡回なので最後に値を追加する
}

int main(){

    int n;
    cin >> n;
    
    vector<int> pre(n), in(n);
    // 先行順巡回
    for(int i = 0; i < n; ++i){
        cin >> pre[i];
    }
    // 中間順巡回
    for(int i = 0; i < n; ++i){
        cin >> in[i];
    }

    vector<int> post;   // 後行順巡回を入れるため配列

    reconstruction(pre, in, post, 0, n);

    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << post[i];
    }
    cout << endl;

    return 0;
}