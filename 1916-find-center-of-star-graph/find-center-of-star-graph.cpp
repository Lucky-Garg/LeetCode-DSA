class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mpp;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        int  n  = mpp.size();
        for(auto it : mpp){
            if(it.second.size() == n-1)return it.first;
        }
        return -1;
    }
};