class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin() , nums.end());
        for(int i = 1 ; i <= 100 ; i++){
            if(!st.count(k*i))return k*i;
        }
        return 101;
    }
};