class Solution {
public:
    bool solve(int idx , int open , string s , int n, vector<vector<int>>&dp){
        if(idx == n){
            return open == 0;
        }
        if(dp[idx][open] != -1)return dp[idx][open];
        bool isValid = false;
        if(s[idx] == '('){
            isValid |= solve(idx+1 , open+1 , s , n , dp);
        }
        else if(s[idx] == ')'){
            if(open>0)isValid |= solve(idx+1 , open-1 , s , n , dp);
        }else{
            isValid |= solve(idx+1 , open+1 , s , n , dp);
            isValid |= solve(idx+1 , open , s , n , dp);
            if(open > 0){
                isValid |= solve(idx+1 , open-1 , s , n , dp);
            }
        }
        return dp[idx][open] = isValid;
    }
    bool checkValidString(string s) {
       int open = 0;
       int n = s.size();
       vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
       return solve(0 , open , s , n , dp);
    }
};