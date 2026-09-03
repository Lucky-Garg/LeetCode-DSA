class Solution {
public:
    bool aE (vector<int>&nums){
        for(auto x : nums){
            if(x % 2 == 1)return false;
        }
        return true;
    }
    bool aO (vector<int>&nums){
        for(auto x : nums){
            if(x % 2 == 0)return false;
        }
        return true;
    }    
    bool uniformArray(vector<int>& nums1) {
        int min_ele = *min_element(nums1.begin() , nums1.end());
        if(aE(nums1) || aO(nums1))return true;
        if(min_ele % 2 == 0)return false;
        return true;
    }
};