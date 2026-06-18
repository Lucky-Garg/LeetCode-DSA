class Solution {
public:
    int solve(vector<int>& nums , int idx , int prev ,vector<vector<int>>&dp ){
        if(idx == nums.size())return 0;
        if(dp[idx][prev+1] != -1)return dp[idx][prev];
        int len = solve(nums , idx+1 , prev , dp);
        if(prev == -1  || (nums[prev] < nums[idx])){
            len  = max(len , 1 + solve(nums , idx+1 , idx , dp));
        }
        return dp[idx][prev+1]  = len;

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1 ,0));
        // for(int i = n-1 ; i >= 0 ; i--){
        //     for(int prev = i-1 ; prev>=-1 ; prev--){
        //         int len = dp[i+1][prev+1];
        //         if(prev == -1  || (nums[prev] < nums[i])){
        //             len  = max(len , 1 + dp[i+1][i+1]);
        //         }
        //         dp[i][prev+1]  = len;
        //     }
        // }
        vector<int>dp(n , 1);
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i] , 1 + dp[prev]);
                }
            }
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};