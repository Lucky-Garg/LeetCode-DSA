class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int cnt = 0;
        long long tempSum = 0;
        int strt = 0;
        for (int i = 0; i < n / 2; i++)
            tempSum += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            if (tempSum > (sum - tempSum))
                cnt++;
            tempSum = tempSum - nums[strt] + nums[(strt + n / 2) % n];
            strt = (strt + 1) % n;
        }

        return cnt;
    }
};