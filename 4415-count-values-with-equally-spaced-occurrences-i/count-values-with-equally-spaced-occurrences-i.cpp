class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int , vector<int>>mpp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]].push_back(i);
        }
        int cntSpecial = 0;
        for(auto x : mpp){
            auto v = x.second;
            if(v.size()!=3)continue;
            if(v[1] - v[0] == v[2]-v[1])cntSpecial++;
        }
        return cntSpecial;
    }
};