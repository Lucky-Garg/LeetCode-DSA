class Solution {
public:
    bool dfs(int node , unordered_map<int , vector<int>>&adj , vector<int>&vis , vector<int>&inRec){
        vis[node] = 1;
        inRec[node] = 1;

        for(auto v : adj[node]){
            if(!vis[v]){
                if(dfs(v , adj , vis , inRec)) return true;
            }
            if(inRec[v]) return true;
        } 

        inRec[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int  , vector<int>>adj;

        for(int i = 0 ; i< n ; i++){
            for(auto x : graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>vis(n , 0) , inRec(n);

        for(int i = 0 ; i< n ; i++){
            if(!vis[i]){
                dfs(i , adj , vis , inRec);
            }
        }

        vector<int>ans;
        for(int  i = 0 ; i < n ; i++){
            if(!inRec[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};