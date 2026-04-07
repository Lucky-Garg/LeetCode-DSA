class Solution {
public:
    void solve(vector<int>& nums , int idx , vector<vector<int>>&ans , vector<int>&temp ){
        if(idx >= nums.size()){
            if(temp.size() >=2){
                ans.push_back(temp);
                return;
            }
            return ;
        }
        if(temp.empty() || temp.back() <= nums[idx]){
            temp.push_back(nums[idx]);
            solve(nums , idx+1 , ans , temp);
            temp.pop_back();
        }
        solve(nums , idx+1 , ans , temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>st;
        solve(nums , 0 , ans , temp);
        for(auto it : ans){
            st.insert(it);
        }
        ans.clear();
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};