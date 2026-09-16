class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n , 0);
        vector<vector<bool>>list(n , vector<bool>(n , false));
        for(auto it : roads){
            deg[it[0]]++;
            deg[it[1]]++;

            list[it[0]][it[1]] = true;
            list[it[1]][it[0]] = true;
        }
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int rank = deg[i]+deg[j];
                if(list[i][j]){
                    rank -= 1;
                }
                maxi = max(maxi , rank);
            }   
        }
        return maxi;
    }
};