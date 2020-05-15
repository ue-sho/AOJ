#include<iostream>
#include<vector>
using namespace std;

constexpr int NIL = -1;

struct Node{
    int parent;
    int left;
    int right;
};

/* 先行順巡回 */
void preorder(const int node, const vector<Node>& info){
    if(node == NIL){
        return;
    }
    cout << " " << node;
    preorder(info[node].left, info);
    preorder(info[node].right, info);
}

/* 中間順巡回 */
void inorder(const int node, const vector<Node>& info){
    if(node == NIL){
        return;
    }
    inorder(info[node].left, info);
    cout << " " << node;
    inorder(info[node].right, info);
}

/* 後行順巡回 */
void postorder(const int node, const vector<Node>& info){
    if(node == NIL){
        return;
    }
    postorder(info[node].left, info);
    postorder(info[node].right, info);
    cout << " " << node;
}

int main() {

    int n;
    cin >> n;
    vector<Node> info(n, {NIL, NIL, NIL});

    for(int i = 0; i < n; ++i){
        int node, left, right;
        cin >> node >> left >> right;
        info[node].left = left;
        if(left != NIL){
            info[left].parent = node;
        }
        info[node].right = right;
        if(right != NIL){
            info[right].parent = node;
        }
    }

    // 親を見つける
    int parent = 0;
    for(int i = 0; i < n; ++i){
        if(info[i].parent == NIL){
            parent = i;
        }
    }

    cout << "Preorder" << endl;
    preorder(parent, info);
    cout << endl;

    cout << "Inorder" << endl;
    inorder(parent, info);
    cout << endl;
    
    cout << "Postorder" << endl;
    postorder(parent, info);
    cout << endl;

    return 0;
}