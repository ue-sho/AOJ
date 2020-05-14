#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert_tree(int num){
    Node *find = root;
    Node *tmp_parent = NIL;
    Node *obj;

    obj = new Node;
    obj->key = num;
    obj->left = NIL;
    obj->right = NIL;

    while (find != NIL){
        tmp_parent = find;
        if(find->key > obj->key){
            find = find->left;
        }
        else{
            find = find->right;
        }
    }
    obj->parent = tmp_parent;

    if(tmp_parent == NIL){
        root = obj;
    }
    else{
        if(tmp_parent->key > obj->key){
            tmp_parent->left = obj;
        }
        else{
            tmp_parent->right = obj;
        }
    }
}

Node *find_node(int num){
    
    Node *find = root;

    while (find != NIL){
        if(find->key == num){
            return find;
        }
        else if(find->key > num){
            find = find->left;
        }
        else{
            find = find->right;
        }
    }
    return find;
}

Node *getNextNode(Node *node){
    /*** 中間順巡回での次節点 ***/

    if(node->right != NIL){
        Node *ret = node->right;
        while (ret->left != NIL){
            ret = ret->left;
        }
        return ret;
    }

    Node *obj = node->parent;
    while(obj != NIL && node == obj->right){
        node = obj;
        obj = obj->parent;
    }
    return obj;
}

void delete_node(Node *key){

    Node *del;
    Node *chil;

    /*** 削除するやつを決める ***/
    if(key->left == NIL || key->right == NIL){ //keyの子がいないときか1つのとき
        del = key;
    }
    else{   //子が2つの時は、中間順巡回での次節点
        del = getNextNode(key);
    }

    /*** delの子chilを決める ***/
    if(del->left != NIL){ //左が先 
        chil = del->left;
    }
    else{
        chil = del->right;
    }

    //chilの親を決める
    if(chil != NIL){
        chil->parent = del->parent;
    }

    /*** つなぎ変え ***/
    if(del->parent == NIL){ //根ならchilがroot
        root = chil;
    }
    else if(del == del->parent->left){
        del->parent->left = chil;
    }
    else{
        del->parent->right = chil;
    }

    /*** keyの次節点が削除された場合 ***/
    if(del != key){
        key->key = del->key;
    }

    delete del;
}

void inorder(Node *node){

    if(node == NIL){
        return;
    }
    inorder(node->left);
    cout << " " << node->key;
    inorder(node->right);
}

void preorder(Node *node){

    if(node == NIL){
        return;
    }
    cout << " " << node->key;
    preorder(node->left);
    preorder(node->right);
}

int main() {
    
    int n;
    cin >> n;

    string command;
    int num;
    rep(i, n){
        cin >> command;
        if(command == "insert"){
            cin >> num;
            insert_tree(num);
        }
        else if(command == "print"){
            inorder(root);
            cout << "\n";
            preorder(root);
            cout << "\n";
        }
        else if(command == "find"){
            cin >> num;
            Node *tmp = find_node(num);
            if(tmp == NIL){
                cout << "no" << endl;
            }
            else{
                cout << "yes" << endl;
            }
        }
        else{
            cin >> num;
            delete_node(find_node(num));
        }
    }
    return 0;
}