#include <bits/stdc++.h>
using namespace std;
// 当你思考并查集解决的问题的时候，要注意放掉树中的层次化思想，而是要思考成离散湖泊群
// 作为树的一种特殊形式，并查集中层次化的东西被弱化，强调的是连接性
class UnionFind{
public:
    UnionFind(int n){
        rank = vector<int>(n+1,0);
        parent = vector<int>(n+1,0);

        for(int i = 0;i < parent.size();i++){
            parent[i] = i;
        }
    }

    int Find(int u){ // find操作是union操作的基础
        if(u != parent[u]){
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v){
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) return false; // if u and v are already in one set.

        if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }else{
            parent[pu] = pv;
            rank[pu] += 1;
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
};
