class Solution {
public:
    int mini;
    void dfs(int u , unordered_map<int , vector<pair<int,int>>>&adj , vector<int>&vis){
        vis[u] = 1;
        for(auto v : adj[u]){
            mini = min(mini , v.second);
            if(!vis[v.first]){
                dfs(v.first , adj , vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int,int>>>adj ;
        for(auto vec : roads){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<int>vis(n+1 , 0);
        mini = INT_MAX;
        dfs(1 , adj , vis);
        return mini;

    }
};