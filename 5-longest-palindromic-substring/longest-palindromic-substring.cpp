class Solution {
public:
    int isPalindrome(string &s, int i , int j , vector<vector<int>>&dp){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return 0;
        return dp[i][j] = isPalindrome(s , i+1 , j-1 ,dp);
    }   
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        int maxLen = -1 , strtIdx = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isPalindrome(s , i , j , dp)){
                    if(j-i+1 > maxLen){
                        strtIdx = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(strtIdx , maxLen);
    }
};