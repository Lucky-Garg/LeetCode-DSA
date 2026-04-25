class Solution {
public:
    void solve(vector<int>&nums , vector<vector<int>>& ans , int idx){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx ; i< nums.size() ; i++){
            swap(nums[i]  , nums[idx]);
            solve(nums , ans , idx+1);
            swap(nums[i] , nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums , ans , 0);
        set<vector<int>>s(ans.begin() , ans.end());
        ans.clear();
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};