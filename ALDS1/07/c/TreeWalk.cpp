#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

#define MAX 25
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
} info[MAX];

/*先行順巡回*/
void Preorder(int node){
    if(node == NIL){
        return;
    }
    cout << " " << node;
    Preorder(info[node].left);
    Preorder(info[node].right);
}

/*中間順巡回*/
void Inorder(int node){
    if(node == NIL){
        return;
    }
    Inorder(info[node].left);
    cout << " " << node;
    Inorder(info[node].right);
}

/*後行順巡回*/
void Postorder(int node){
    if(node == NIL){
        return;
    }
    Postorder(info[node].left);
    Postorder(info[node].right);
    cout << " " << node;
}

int main() {

    int n;
    cin >> n;
    rep(i, n){ //初期化
        info[i].parent = NIL;
    }

    int id, left, right;
    rep(i, n){
        cin >> id >> left >> right;
        info[id].left = left;
        info[id].right = right;
        if(left != NIL){
            info[left].parent = id;
        }
        if(right != NIL){
            info[right].parent = id;
        }
    }

    int root;
    rep(i, n){
        if(info[i].parent == NIL){
            root = i;
        }
    }

    cout << "Preorder" << endl;
    Preorder(root);
    cout << "\n";
    cout << "Inorder" << endl;
    Inorder(root);
    cout << "\n";
    cout << "Postorder" << endl;
    Postorder(root);
    cout << "\n";

    return 0;
}