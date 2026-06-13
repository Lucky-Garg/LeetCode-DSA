class Solution {
public:
    bool solve(int idx , string s , vector<string>& wordDict , int n , vector<int>&dp){
        if(idx == n){
            return 1;
        }
        if(dp[idx] != -1)return dp[idx];
        for(int i = 1 ; i + idx <= n ; i++){
            string temp = s.substr(idx , i);
            if((find(wordDict.begin() , wordDict.end() , temp) != wordDict.end()) && solve(idx+i , s, wordDict , n , dp)){
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(find(wordDict.begin() , wordDict.end() , s) != wordDict.end()){
            return true;
        }
        vector<int>dp(n+1,-1);
        return solve(0 , s , wordDict , n , dp);
    }
};