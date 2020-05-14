#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

#define MAX 25
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
} info[MAX];


int depth[MAX];
int height[MAX];

void print(int node){

    cout << "node " << node;
    cout << ": parent = " << info[node].parent;
    
    cout << ", sibling = ";
    if(info[node].parent == NIL){
        cout << -1;
    }
    else if(info[info[node].parent].left == node){
        cout << info[info[node].parent].right;
    }
    else if(info[info[node].parent].right == node){
        cout << info[info[node].parent].left;
    }

    
    cout << ", degree = ";
    int deg = 0;
    if(info[node].left != NIL){
        deg++;
    }
    if(info[node].right != NIL){
        deg++;
    }
    cout << deg;
    
    cout << ", depth = " << depth[node];
    cout << ", height = " << height[node] << ", ";

    if(info[node].parent == NIL){
        cout << "root";
    }
    else if(info[node].left == NIL && info[node].right == NIL){
        cout << "leaf";
    }
    else{
        cout << "internal node";
    }

    cout << "\n";
}

void setDepth(int node, int dep){
    depth[node] = dep;
    if(info[node].right != NIL){
        setDepth(info[node].right, dep+1);
    }
    if(info[node].left != NIL){
        setDepth(info[node].left, dep+1);
    }
}

/*ここ分からなかった*/
int setHeight(int node){
    int h1 = 0, h2 = 0;
    if(info[node].left != NIL){
        h1 = setHeight(info[node].left) + 1;
    }
    if(info[node].right != NIL){
        h2 = setHeight(info[node].right) + 1;
    }

    return height[node] = max(h1, h2);
}

int main() {

    int n;
    cin >> n;
    rep(i, n){ //初期化
        info[i].parent = NIL;
    }

    int node, left, right;
    rep(i, n){
        cin >> node >> left >> right;
        info[node].left = left;
        info[node].right = right;
        if(left != NIL){
            info[left].parent = node;
        }
        if(right != NIL){
            info[right].parent = node;
        }
    }

    int root;
    rep(i, n){
        if(info[i].parent == NIL){
            root = i;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    rep(i, n){
        print(i);
    }

    return 0;
}