class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = -1;
        vector<int> prefixGcd;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd.push_back(gcd(nums[i] , maxi));
        }
        sort(prefixGcd.begin() , prefixGcd.end());
        long long sum = 0;
        int i = 0 , j = prefixGcd.size()-1;
        while(i<j){
            sum += gcd(prefixGcd[i] , prefixGcd[j]);
            i++ , j--;
        }
        return sum;
    }
};