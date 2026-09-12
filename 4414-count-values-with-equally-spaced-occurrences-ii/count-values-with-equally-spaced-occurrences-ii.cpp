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
            if(v.size()<3)continue;
            int diff = v[1]-v[0];
            bool flg = true;
            for(int i = 0 ; i < v.size()-1 ; i++){
                if(v[i] + diff != v[i+1]){
                    flg = false;
                    break;
                }
            }

            if(flg)cntSpecial++;
        }
        return cntSpecial;
    }
};