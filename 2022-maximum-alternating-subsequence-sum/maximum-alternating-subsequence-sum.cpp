class Solution {
public:
    long long solve(vector<int>&nums , int idx , bool flg , vector<vector<long long>>&dp ){
        if(idx >= nums.size())return 0;
        if(dp[idx][flg] != -1)return dp[idx][flg];
        long long nonPick = solve(nums , idx+1 , flg,dp);
        long long val = nums[idx];
        if(flg == false){
            val = -val;
        }
        long long pick = solve(nums , idx+1 , !flg ,  dp) + val;

        return dp[idx][flg] =  max(pick , nonPick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        bool flg = true;
        vector<vector<long long>>dp(n+1 , vector<long long>(2 , -1));
        return solve(nums , 0 ,flg , dp);
    }
};