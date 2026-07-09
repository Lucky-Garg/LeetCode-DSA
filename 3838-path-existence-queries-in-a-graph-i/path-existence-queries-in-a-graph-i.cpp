class Solution {
public:
    // bool dfs(int s , int d , unordered_map<int , vector<int>>&adj , vector<int>&vis){
    //     vis[s] = 1;
    //     if(s == d)return true;
    //     for(auto v : adj[s]){
    //         if(!vis[v]){
    //             if(dfs(v , d , adj , vis))return true;
    //         }
    //     }
    //     return false;
    // }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // unordered_map<int , vector<int>>adj;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         if(abs(nums[i] - nums[j]) <= maxDiff){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // vector<bool>ans;
        // for(auto v : queries){
        //     int s = v[0];
        //     int d = v[1];
        //     vector<int>vis(n,0);
        //     if(dfs(s , d , adj , vis))ans.push_back(true);
        //     else{
        //         ans.push_back(false);
        //     }
        // }
        // return ans;

        vector<int>comp(n,0);
        int id  = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                id++;
            }
            comp[i] = id;
        }
        vector<bool>ans;
        for(auto v : queries){
            int s = v[0];
            int d = v[1];
            ans.push_back(comp[s] == comp[d]);
        }
        return ans;
    }
};