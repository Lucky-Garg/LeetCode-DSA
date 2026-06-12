class Solution {
public:
    int solve(int idx , int buy , vector<int>&price , vector<vector<int>>&dp ){
        if(idx == price.size()){
            return 0;
        }
        if(dp[idx][buy] != -1)return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-price[idx] + solve(idx+1 , 0 , price , dp) ,
                            solve(idx+1 , 1 , price , dp));
        }
        else{
            profit = max(price[idx] + solve(idx+1 , 1 , price , dp) ,
                         solve(idx+1 , 0 , price , dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size() , vector<int>(2,-1));
        return solve(0 , 1 , prices , dp);
    }
};