#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

/*模範解答*/

#define MAX 100000
#define NIL -1

struct Node {
    int parent;
    int left;   //一番左の子を入れる　NIL(-1)なら子がいない
    int right;  //再帰的に子を入れる
};

Node info[MAX];
int depth[MAX];

void print(int node){

    cout << "node " << node;
    cout << ": parent = " << info[node].parent; 
    cout  << ", depth = " << depth[node] << ", ";
    
    if(info[node].parent == NIL){
        cout << "root, ";
    }
    else if(info[node].left == NIL){
        cout << "leaf, ";
    }
    else{
        cout << "internal node";
    }

    cout << "[";
    for(int i=0, child=info[node].left; child!=NIL; i++, child=info[child].right){
        if(i){
            cout << ", ";
        }
        cout << child;
    }
    cout << "]" << endl;
}

int setDepth(int node, int dep){
    depth[node] = dep;
    if(info[node].right != NIL){    //右は全部同じ深さ
        setDepth(info[node].right, dep);
    }
    if(info[node].left != NIL){     //左は深くなる
        setDepth(info[node].left, dep+1);
    }
}

int main() {

    int n;
    cin >> n;
    rep(i, n){ //初期化
        info[i].parent = info[i].left = info[i].right = NIL;
    }

    int node, child_num, child;
    rep(i, n){
        cin >> node >> child_num;
        int recursion;
        rep(j, child_num){
            cin >> child;
            if(j==0){
                info[node].left = child;
            }
            else{
                info[recursion].right = child;
            }

            recursion = child;
            info[child].parent = node; //再帰的に子をいれていく
        }
    }

    int parent;
    rep(i, n){
        if(info[i].parent == NIL){
            parent = i;
        }
    }

    setDepth(parent, 0);

    rep(i, n){
        print(i);
    }

    return 0;
}