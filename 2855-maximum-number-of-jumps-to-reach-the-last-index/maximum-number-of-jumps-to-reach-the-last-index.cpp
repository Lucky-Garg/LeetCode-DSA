class Solution {
public:
    // int func(vector<int>&nums , int idx , int x , vector<int>&dp ){
    //     if(idx == nums.size()-1){
    //         return 0;
    //     }
    //     if(dp[idx] != -1)return dp[idx];
    //     int ans = -1;
    //     for(int i = idx+1 ; i<nums.size() ; i++){
    //         if(nums[i] - nums[idx] >= -x && nums[i]-nums[idx] <= x){
    //             int jumps = func(nums , i , x , dp);
    //             if(jumps != -1){
    //                 ans = max(ans , 1+jumps);
    //             }
    //         }
    //     }
    //     return dp[idx] = ans;
    // }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n , -1);
        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(dp[j] != -1 && nums[i] - nums[j] >= -target 
                && nums[i] - nums[j] <= target){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};