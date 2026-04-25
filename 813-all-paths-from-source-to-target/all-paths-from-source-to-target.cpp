class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<vector<int>>&adj , int s , vector<int>&temp){
        temp.push_back(s);
        if(s == adj.size()-1){
            ans.push_back(temp);
        }
        for(auto it : adj[s]){
            solve(ans , adj , it , temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n =adj.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans , adj , 0 , temp);
        return ans;
    }
};