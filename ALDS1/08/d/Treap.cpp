#include<iostream>

using namespace std;

struct Node{
  int key, priority;
  Node* right;
  Node* left;
};

Node* right_rotate(Node* t){
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node* left_rotate(Node* t){
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* insert(Node* t, int key, int priority){

    if(t == NULL){
        Node* t = new Node;
        t->left = NULL;
        t->right = NULL;
        t->key = key;
        t->priority = priority;
        return t;
    }
    if(key == t->key){
        return t;
    }
    if(key < t->key){
        t->left = insert(t->left, key, priority);
        if(t->priority < t->left->priority){
            t = right_rotate(t);
        } 
    }
    else{
        t->right = insert(t->right, key, priority);
        if(t->priority < t->right->priority){
            t = left_rotate(t);
        }
    }
    return t;
}

Node* delete_key(Node* t, int key){
    if(t == NULL){
        return NULL;
    }
    if(key == t->key){
        if(t->left  == NULL && t->right == NULL){
            return NULL;
        }
        else if(t->left == NULL){
            t = left_rotate(t);
        } 
        else if(t->right == NULL){
            t = right_rotate(t);
        } 
        else{
            if(t->left->priority > t->right->priority){
                t = right_rotate(t);
            }
            else{
                t = left_rotate(t);
            } 
        }
        return delete_key(t, key);
    }
    if(key < t->key){
        t->left = delete_key(t->left, key);
    }
    else{
        t->right = delete_key(t->right, key);
    } 
    return t;
}

void find(Node* t, int key){
    while(t != NULL && key != t->key){
        if(key < t->key){
            t = t->left;
        }
        else{
            t = t->right;
        } 
    }
    if(t == NULL){
        cout << "no" << endl;
    }
    else{
        cout << "yes" << endl;
    } 
}

// 中間順巡回
void inorder(Node* t){
    if(t == NULL){
        return;
    }
    inorder(t->left);
    cout << " " << t->key;
    inorder(t->right);
}

// 先行順巡回
void preorder(Node* t){
    if(t == NULL){
        return;
    }
    cout << " " << t->key;
    preorder(t->left);
    preorder(t->right);
}

int main(){
    Node* root = NULL;
    
    int n;
    cin >> n;

    string s;
    int key, priority;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s == "insert"){
            cin >> key >> priority;
            root = insert(root, key, priority);
        }
        else if(s == "delete"){
            cin >> key;
            root = delete_key(root, key);
        }
        else if(s == "find"){
            cin >> key;
            find(root, key);
        }
        else {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }

    return 0;
}
