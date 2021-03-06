#include<iostream>
#include<vector>
using namespace std;

class UnionFind {
public:
    vector<int> d;
    
    UnionFind(int n = 0) : d(n, -1) {}

    int find(int x) {
        if(d[x] < 0){
            return x;
        }
        return d[x] = find(d[x]); // メモ化再帰
    }
    
    bool unite(int x, int y) {
        x = find(x); 
        y = find(y);
        if(x == y){
            return false;
        }
        if(size(x) < size(y)){
            swap(x,y);
        } 
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    
    bool same(int x, int y) { 
        return find(x) == find(y);
    }
    
    int size(int x) { 
        return -d[find(x)];
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    for(int i = 0; i < m; ++i){
        int s, t;
        cin >> s >> t;
        uf.unite(s, t);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int x, y;
        cin >> x >> y;
        if(uf.same(x, y)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

    return 0;
}