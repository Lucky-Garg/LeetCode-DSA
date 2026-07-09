class Solution {
public:
    void solve(int u ,vector<vector<int>>& graph , vector<int>&temp ,vector<int>&vis , vector<vector<int>>& ans){
        vis[u] = 1;
        temp.push_back(u);
        if(u == graph.size()-1){
            ans.push_back(temp);
            vis[u] = 0;
        }
        for(auto v : graph[u]){
            if(!vis[v]){
                solve(v , graph , temp , vis , ans);
            }
        }
        vis[u] = 0;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n,0);
        solve(0, graph , temp , vis , ans );
        return ans;
    }
};