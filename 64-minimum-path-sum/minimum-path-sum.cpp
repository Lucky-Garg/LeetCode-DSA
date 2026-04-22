class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m));
        if(n == 1 && m == 1)return grid[0][0];
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int u = 0 , l = 0;
                    if( i > 0){
                        u = dp[i-1][j];
                    }
                    else{
                        u = INT_MAX;
                    }
                    if( j > 0){
                        l = dp[i][j-1];
                    }
                    else{
                        l = INT_MAX;
                    }
                    dp[i][j] = grid[i][j] + min(u , l);
                }

            }
        }
        return dp[n-1][m-1];
    }
};