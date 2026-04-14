class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>mpp;
        set<int>s(nums2.begin(),nums2.end());
        vector<int>ans;
        for(auto it : nums1){
            mpp[it]++;
        }
        for(auto it :s){
            if(mpp.count(it)){
                ans.push_back(it);
            }

        }
        return ans;
    }
};