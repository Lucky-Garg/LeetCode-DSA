class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        int maxi = *max_element(nums.begin() , nums.end());
        if(maxi != n-1)return false;
        unordered_map<int, int>mpp;
        for(int x : nums){
            mpp[x]++;
        }
        for(auto x : nums){
            if(x == maxi){
                if(mpp[x] != 2)return false;
            }
            else{
                if(mpp[x] != 1)return false;
            }
        }
        return true;
    }
};