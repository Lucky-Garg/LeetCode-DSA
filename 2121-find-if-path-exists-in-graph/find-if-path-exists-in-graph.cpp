class DSU {
    vector<int>parent , size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    int findP(int node){
        if(parent[node] == node) return node;
        return parent[node] = findP(parent[node]);
    }

    void unionBySize(int u , int v){
        int ult_u = findP(u);
        int ult_v = findP(v);
        if(ult_u == ult_v)return ;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }
        return (ds.findP(source) == ds.findP(destination));
    }
};