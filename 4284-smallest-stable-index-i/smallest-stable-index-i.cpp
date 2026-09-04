class Solution {
public:
    int maxi(vector<int>&nums , int k){
        int mx = INT_MIN;
        for(int i = 0 ; i<=k ; i++){
            mx = max(mx , nums[i]);
        }
        return mx;
    }
    int mini(vector<int>&nums ,int k){
        int mn = INT_MAX;
        for(int i = k ; i<nums.size() ; i++){
            mn = min(mn , nums[i]);
        }
        return mn;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = nums.size()+1;
        for(int i = 0 ; i < nums.size() ; i++){
            int mx = maxi(nums , i);
            int mn = mini(nums , i);
            if(mx-mn <= k){
                ans = min(ans , i);
            }
        }
        if(ans == nums.size()+1)return -1;
        return ans;
    }
};