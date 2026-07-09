class Solution {
public:
    bool biPartite(int s , unordered_map<int,vector<int>>&adj, vector<int>&color ){
        for(auto v : adj[s]){
            if(color[v] == -1){
                color[v] = 1 - color[s];
                if(biPartite(v , adj , color))return true;
            }
            else {
                if(color[v] == color[s])return true;
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto v : dislikes){
            int s = v[0];
            int d = v[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        vector<int>color(n+1 , -1);
        for(int i = 1 ; i <= n ;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(biPartite(i , adj , color))return false;
            }
        }
        return true;
    }
};