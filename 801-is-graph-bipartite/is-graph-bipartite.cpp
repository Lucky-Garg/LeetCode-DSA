class Solution {
public:
    bool biPartite(int s ,vector<vector<int>>& adj , vector<int>&color ){
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
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int>color(adj.size() , -1);
        int n = adj.size();
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(biPartite(i , adj , color))return false;
            }
        }
        return true;
    }
};