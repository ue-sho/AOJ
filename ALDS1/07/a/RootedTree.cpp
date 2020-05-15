#include<iostream>
#include<vector>
using namespace std;

constexpr int NIL = -1;

struct Node {
    int parent;
    int left;   //一番左の子を入れる　NIL(-1)なら子がいない
    int right;  //再帰的に子を入れる
};

void print_tree(const vector<Node>& info, const vector<int>& depth, const int n){

    for(int node = 0; node < n; ++node){
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
            cout << "internal node, ";
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
}

void set_depth(int node, int dep, const vector<Node>& info, vector<int>& depth){
    depth[node] = dep;
    if(info[node].right != NIL){    //右は全部同じ深さ
        set_depth(info[node].right, dep, info, depth);
    }
    if(info[node].left != NIL){     //左は深くなる
        set_depth(info[node].left, dep + 1, info, depth);
    }
}

int main() {

    int n;
    cin >> n;
    
    vector<Node> info(n, {NIL, NIL, NIL});  // 全てNILで初期化

    for(int i = 0; i < n; ++i){
        int node, child_num, recursion;
        cin >> node >> child_num;
        for(int j = 0; j < child_num; ++j){
            int child;
            cin >> child;
            // 再帰的に子をいれていく
            if(j == 0){
                info[node].left = child;
            }
            else{
                info[recursion].right = child;
            }
            recursion = child;
            info[child].parent = node;
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

    print_tree(info, depth, n);

    return 0;
}