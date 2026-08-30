class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int , vector<int>>mpp;
        for(int i = 0 ; i< nums.size() ; i++){
            mpp[nums[i]].push_back(i);
        }

        int cnt = 0;
        for(auto it : mpp){
            auto v = it.second;
            bool flg = true;
            for(int i = 0 ; i < v.size()-1 ; i++){
                if(v[i+1]!= v[i]+1){
                    flg = false;
                }
            }
            if(flg)cnt++;
        }
        return cnt;
    }
};