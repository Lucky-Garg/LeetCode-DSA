class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<int>>adj;
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            int lenI = adj[i].size();
            for(int j = i+1 ; j < n ; j++){
                int lenJ = adj[j].size();
                if(find(adj[i].begin() , adj[i].end() , j) != adj[i].end()){
                    lenJ -= 1;
                }
                maxi = max(maxi , lenI + lenJ);
            }   
        }
        return maxi;
    }
};