class Solution {
public:
    bool biPartite(int s ,vector<vector<int>>& adj , vector<int>&color , int currColor){
        color[s] = currColor;
        for(auto v : adj[s]){
            if(color[v] == color[s]){
                return false;
            }
            else if(color[v] == -1){
                int colorV = 1 - currColor;
                if(biPartite(v , adj , color , colorV) == false)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int>color(adj.size() , -1);
        for(int i = 0 ; i < adj.size() ; i++){
            if(color[i] == -1){
                if(biPartite(i , adj , color , 1 ) == false)return false;
            }
        }
        return true;
    }
};