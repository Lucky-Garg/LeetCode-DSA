class Solution {
public:
    bool check(vector<int>& nums, int mid, int days) {
        int cntDays = 1;
        int cap = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > mid)return false;
            if (cap + nums[i] > mid) {
                cntDays++;
                cap = 0;
            }
            cap += nums[i];
        }
        return cntDays <= days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int l = 0, h = accumulate(nums.begin(), nums.end(), 0);
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(nums, mid, days)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};