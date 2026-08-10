class Solution {
public:
    int find(vector<int>&nums , int x){
        if( x < 0)return 0;
        int ans = 0;
        int i = 0 , j = 0;
        int sum = 0;
        while(j < nums.size()){
            sum += nums[j];
            while(sum > x){
                sum -= nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums , goal ) - find(nums , goal-1);
    }
};