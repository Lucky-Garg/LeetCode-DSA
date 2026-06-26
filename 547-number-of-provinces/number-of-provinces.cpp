// class DSU{
// public:
//     vector<int>parent,size;
//     DSU(int n){
//         size.resize(n+1 ,1);
//         parent.resize(n+1);
//         for(int i = 0 ; i<=n ; i++){
//             parent[i]=i;
//         }
//     }
//     int findP(int node){
//         if(node == parent[node])return node;
//         return parent[node]=findP(parent[node]);
//     }
//     void unionBySize(int u , int v){
//         int ult_u = findP(u);
//         int ult_v = findP(v);
//         if(ult_u == ult_v)return ;
//         if(size[ult_u] < size[ult_v]){
//             parent[ult_u] = ult_v;
//             size[ult_v]+=size[ult_u];
//         }
//         else{
//             parent[ult_v] = ult_u;
//             size[ult_u]+=size[ult_v];
//         }
//     }
// };
class Solution {
public:

    void dfs(int s , unordered_map<int , vector<int>>&adj , vector<int>&vis){
        vis[s] = 1;
        for(auto v : adj[s]){
            if(!vis[v]){
                dfs(v , adj , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // int n = isConnected.size();
        // DSU ds(n);
        // for(int i = 0 ; i<n ; i++){
        //     for(int j = 0 ; j<n ;j++){
        //         if(isConnected[i][j] == 1){
        //             ds.unionBySize(i,j);
        //         }
        //     }
        // }
        // int cnt = 0;
        // for(int i = 0 ; i<n ; i++){
        //     if(ds.parent[i] == i)cnt++;
        // }
        // return cnt;
        unordered_map<int , vector<int>>adj;
        for(int i = 0 ; i < isConnected.size() ; i++){
            for(int j = 0 ; j < isConnected[0].size() ; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(isConnected.size()+1 ,0);
        for(int i = 1 ; i <= isConnected.size() ; i++){
            if(!vis[i]){
                cnt ++;
                dfs(i , adj , vis);
            }
        }
        return cnt;
    }
};