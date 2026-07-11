class Solution {
public:
    void dfs(int s , unordered_map<int , vector<int>>&adj , vector<int>&vis , int &N , int &E){
        vis[s] = 1;
        N ++ ;
        E += adj[s].size();
        for(auto v : adj[s]){
            if(!vis[v]){
                dfs(v , adj , vis , N , E);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj;
        for(auto vec  : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int cntComponent = 0;
        for(int i =  0 ; i < n ; i++){
            if(!vis[i]){
                int N = 0;
                int E = 0;
                dfs(i , adj , vis , N , E);
                E /= 2 ;
                if(E == (N*(N-1)/2)){
                    cntComponent ++;
                }
            }
        }
        return cntComponent;
    }
};