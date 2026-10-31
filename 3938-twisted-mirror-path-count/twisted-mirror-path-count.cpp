class Solution {
public:
    int left = 0, up = 1;
    int MOD = 1e9 + 7;
    int n;
    int m;
    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom,
              vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (dp[i][j][cameFrom] != -1) {
            return dp[i][j][cameFrom];
        }
        if (grid[i][j] == 1) {
            if (cameFrom == left) {
                return dp[i][j][cameFrom] = solve(grid, i + 1, j, up, dp);
            } else {
                return dp[i][j][cameFrom] = solve(grid, i, j + 1, left, dp);
            }
        }
        int totalPath = 0;

        totalPath = (totalPath + solve(grid, i + 1, j, up, dp)) % MOD;
        totalPath = (totalPath + solve(grid, i, j + 1, left, dp)) % MOD;

        return dp[i][j][cameFrom] = totalPath;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));

        return solve(grid, 0, 0, left, dp);
    }
};