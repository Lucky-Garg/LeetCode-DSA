class Solution {
public:
    int path(int i , int j , vector<vector<int>>& grid , vector<vector<int>>&dp){
        if(i == 0 && j == 0)
            return 1;
        if( i < 0 || j < 0)
            return 0;
        if(grid[i][j] == 1)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int u = path(i-1 , j , grid , dp);
        int l = path(i , j-1 , grid , dp);
        return dp[i][j] = (u+l);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1)return 0;
        vector<vector<int>>dp(m , vector<int>(n,-1));
        return path(m-1 , n -1 , grid , dp);
    }
};