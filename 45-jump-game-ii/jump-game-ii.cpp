class Solution {
public:
    int solve(vector<int>&nums , int idx , vector<int>&dp ){
        if(idx >= nums.size()-1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans =  INT_MAX;
        for(int i = 1 ; i <= nums[idx]; i++){
            int temp = solve(nums , idx+i , dp);
            if(temp != INT_MAX){
                ans = min(ans , 1+temp);
            }
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        return solve(nums , 0 ,dp);
        
    }
};