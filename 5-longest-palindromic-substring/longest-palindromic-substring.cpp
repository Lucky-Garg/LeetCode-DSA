class Solution {
public:
    int palindrome(string &s , int i  , int j , vector<vector<int>>&dp){
        if(i >= j) return 1;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = palindrome(s , i+1 , j-1 , dp);
        }
        return dp[i][j] = 0;

    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(1001 , vector<int>(1001 , -1));
        int sp = -1;
        int len = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(palindrome(s , i , j , dp) == 1){
                    if(len < j-i+1){
                        len = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp , len);
    }
};