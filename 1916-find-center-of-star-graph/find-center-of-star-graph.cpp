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
        vector<int>degree(n+1);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            degree[u]++;
            degree[v]++;
        }
        for(int i = 1 ; i<=n ; i++){
            if(degree[i] == n-1)return i;
        }
        return -1;
    }
};