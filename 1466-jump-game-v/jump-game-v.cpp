class Solution {
public:
    int solve(vector<int>&nums , int i , int d , vector<int>&dp){
        if(dp[i] != -1)return dp[i];
        int result = 1;
        for(int k = i-1 ; ((k>=i-d) && k>=0) ; k--){
            if(nums[i] <= nums[k]) break;
            result = max(result , 1+solve(nums , k , d ,dp));
        }
        for(int k = i+1 ; ((k<=i+d) && k<=nums.size()-1) ; k++){
            if(nums[i] <= nums[k]) break;
            result = max(result , 1+solve(nums , k , d , dp));
        }
        return dp[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        vector<int>dp(arr.size() , -1);
        int result = -1;
        for(int i = 0 ; i< arr.size() ; i++){
            result = max(result , solve(arr , i , d , dp));
        }
        return result;
    }
};