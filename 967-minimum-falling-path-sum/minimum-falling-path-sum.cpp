class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    //     if (i >= mat.size() || j < 0 || j >= mat.size())
    //         return INT_MAX;
    //     if (i == mat.size() - 1)
    //         return mat[i][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int down = solve(i + 1, j, mat, dp);
    //     int rightDig = solve(i + 1, j + 1, mat, dp);
    //     int leftDig = solve(i + 1, j - 1, mat, dp);
    //     return dp[i][j] = mat[i][j] + min(down, min(rightDig, leftDig));
    // }
    void solveTab(vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = mat[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down, leftDig = INT_MAX, rightDig = INT_MAX;
                down = dp[i + 1][j];
                if (j < n - 1) {
                    rightDig = dp[i + 1][j + 1];
                }
                if (j > 0) {
                    leftDig = dp[i + 1][j - 1];
                }
                dp[i][j] = mat[i][j] + min(down, min(leftDig, rightDig));
            }
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        solveTab(matrix, dp);
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};