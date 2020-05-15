#include<iostream>
#include<vector>
using namespace std;

constexpr int NIL = -1;

struct Node {
    int parent;
    int left;   //一番左の子を入れる　NIL(-1)なら子がいない
    int right;  //再帰的に子を入れる
};

void print_tree(const vector<Node>& info, const vector<int>& depth, const vector<int>& height, const int n){

    for(int node = 0; node < n; ++node){
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
            cout << "root" << endl;
        }
        else if(info[node].left == NIL && info[node].right == NIL){
            cout << "leaf" << endl;
        }
        else{
            cout << "internal node" << endl;
        }
    }
}

void set_depth(int node, int dep, const vector<Node>& info, vector<int>& depth){
    depth[node] = dep;
    if(info[node].right != NIL){
        set_depth(info[node].right, dep + 1, info, depth);
    }
    if(info[node].left != NIL){
        set_depth(info[node].left, dep + 1, info, depth);
    }
}

int set_height(int node, const vector<Node>& info, vector<int>& height){
    int h1 = 0, h2 = 0;
    if(info[node].left != NIL){
        h1 = set_height(info[node].left, info, height) + 1;
    }
    if(info[node].right != NIL){
        h2 = set_height(info[node].right, info, height) + 1;
    }
    return height[node] = max(h1, h2);
}


int main() {

    int n;
    cin >> n;
    
    vector<Node> info(n, {NIL, NIL, NIL});  // NILで初期化

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

    vector<int> depth(n);
    set_depth(parent, 0, info, depth);

    vector<int> height(n);
    set_height(parent, info, height);

    print_tree(info, depth, height, n);

    return 0;
}