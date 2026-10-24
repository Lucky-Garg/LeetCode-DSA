class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int pk = 0;
        int vl = 0;
        int n = nums.size();

        for(int i = 1 ;i < n-1 ; i++){
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1]) pk += nums[i];
            if(nums[i] < nums[i+1] && nums[i] < nums[i-1]) vl += nums[i];
        }

        return (pk-vl);
    }
};