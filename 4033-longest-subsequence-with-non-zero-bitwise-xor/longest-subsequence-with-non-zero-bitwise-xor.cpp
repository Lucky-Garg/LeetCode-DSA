class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo = 0;
        bool zero = true;
        for(auto x : nums){
            xo ^= x;
            if(x > 0)zero = false;
        }
        if(zero)return 0;
        if(xo != 0)return nums.size();
        return nums.size()-1;
    }
};