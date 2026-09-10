class Solution {
public:
    bool solve(vector<int>&arr  , int idx , int n , int x , vector<vector<int>>&dp){
        if(idx == arr.size()-1){
            return arr[idx] == x;
        }
        if(x == 0)return true;
        if(dp[idx][x] != -1)return dp[idx][x];
        bool pick = false;
        if(arr[idx] <= x){
            pick = solve(arr , idx+1 , n , x-arr[idx] , dp);
        }
        bool notPick = solve(arr , idx+1 , n , x , dp);
        return dp[idx][x] = pick || notPick;
    }
    bool canPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin() , arr.end() , 0);
        int n = arr.size();
        if(totalSum % 2 == 1)return false;
        int x = totalSum/2;
        vector<vector<int>>dp(n+1 , vector<int>(x+1 , -1));
        return solve(arr , 0 , n , x , dp);
    }
};