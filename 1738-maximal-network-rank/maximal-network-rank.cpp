class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int , unordered_set<int>>adj;
        for(auto it : roads){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            int lenI = adj[i].size();
            for(int j = i+1 ; j < n ; j++){
                int lenJ = adj[j].size();
                if(adj[i].count(j)){
                    lenJ -= 1;
                }
                maxi = max(maxi , lenI + lenJ);
            }   
        }
        return maxi;
    }
};