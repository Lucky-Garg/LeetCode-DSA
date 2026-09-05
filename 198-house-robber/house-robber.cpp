class Solution {
public:
    // int solve(int idx , vector<int>& nums){
    //     if( idx < 0 )return 0;
    //     if( idx == 0 )return nums[0];
    //     return max(nums[idx] + solve(idx-2 , nums) , solve(idx-1 , nums));
    // }
    int func(vector<int>&nums , int idx , vector<int>&dp){
        if(idx == nums.size()-1)return nums[nums.size()-1];
        if(idx >= nums.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        int pick = nums[idx] + func(nums , idx+2 , dp);
        int nonPick = func(nums , idx+1 , dp);
        return dp[idx] = max(pick , nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // int curr = 0 , prev1 , prev2 ;
        // prev2 = nums[0];
        // prev1 = max(nums[0] , nums[1]);
        // for(int i = 2 ; i <n ; i++){
        //     curr = max(nums[i] + prev2 ,prev1);
        //     prev2 = prev1;
        //     prev1 = curr;
        // }
        // return prev1;
        vector<int>dp(n+1 , -1);
        return func(nums , 0 , dp);
    }
};