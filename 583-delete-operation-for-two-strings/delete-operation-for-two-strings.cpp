class Solution {
public:
    int lcs(string &s , string &t , int n , int m , vector<vector<int>>&dp){
        if(n == 0 || m == 0)return 0;
        if(dp[n][m] != -1)return dp[n][m];
        if( s[n-1] == t[m-1]){
            return dp[n][m] = 1 + lcs(s , t , n-1 , m-1 , dp);
        }
        else{
            return dp[n][m] =  max(lcs(s , t , n-1 , m , dp) , lcs(s,t , n , m-1 , dp));
        }
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size() , m = word2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        return (n+m) - 2*lcs(word1 , word2 , n , m , dp);
    }
};