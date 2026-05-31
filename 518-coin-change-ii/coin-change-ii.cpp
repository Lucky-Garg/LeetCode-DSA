class Solution {
public:
    int solve(vector<int>&nums , int idx , int x , vector<vector<int>>&dp){
        if(x == 0)return 1;
        if(idx == 0){
            if(x % nums[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[idx][x] != -1)return dp[idx][x];
        int notPick = solve(nums , idx-1 , x , dp);
        int pick = 0;
        if(nums[idx] <= x){
            pick = solve(nums , idx , x-nums[idx] , dp);
        }
        return dp[idx][x] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1 , -1));
        return solve(coins , n-1 , amount , dp);
    }
};