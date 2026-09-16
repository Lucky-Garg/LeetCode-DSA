class Solution {
public:
    vector<vector<int>>dp();
    int solve(string s , string t  , int m , int n , vector<vector<int>>&dp){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1)return dp[m][n];
        if(s[m-1] == t[n-1]){
            return dp[m][n] = 1 + solve(s , t , m-1 , n-1 , dp);
        }
        return dp[m][n] = max(solve(s , t , m-1 , n , dp) , solve(s , t , m , n-1 , dp));
    }
    int longestCommonSubsequence(string s, string t) {
        int m = s.size() , n = t.size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1));

        for(int i = 0 ; i <= m ; i++){
            dp[i][0] = 0;
        }
        for(int j = 0 ; j <= n ; j++){
            dp[0][j] = 0;
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};