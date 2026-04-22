class Solution {
public:
    // int solve(int i , int j ,vector<vector<int>>& grid, int n ,vector<vector<int>>&dp){
    //     if(i == n-1)return grid[i][j];
    //     if(i>=n)return INT_MAX;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int down = solve(i+1 , j , grid , n , dp);
    //     int dig = solve(i+1 , j+1 , grid , n , dp);          memoization not workkkk !!!!!
    //     return dp[i][j] = min(down , dig) + grid[i][j];
    // }
    int minimumTotal(vector<vector<int>>& grid) {
        int n  = grid.size() ;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j = 0 ; j<n ; j++){
            dp[n-1][j] = grid[n-1][j];
        }
        for(int i = n-2 ; i>= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                int down = dp[i+1][j];
                int dig = dp[i+1][j+1];
                dp[i][j] = min(down , dig) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};