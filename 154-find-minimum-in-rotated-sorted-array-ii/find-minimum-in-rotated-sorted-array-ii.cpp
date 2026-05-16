class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int>s(nums.begin() , nums.end());
        vector<int>ans(s.begin() ,  s.end());
        return *min_element(ans.begin() , ans.end());
    }
};