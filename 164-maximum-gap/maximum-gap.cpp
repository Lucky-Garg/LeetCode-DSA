class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        sort(nums.begin() , nums.end());
        int maxi = -1;
        for(int i = 0 ; i<n-1; i++){
            maxi = max(maxi , nums[i+1]-nums[i]);
        }
        return maxi;
    }

};