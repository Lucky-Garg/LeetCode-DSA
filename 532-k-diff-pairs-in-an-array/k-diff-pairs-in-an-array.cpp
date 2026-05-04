class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]] ++;
        }
        for(auto it : mpp){
            if( k != 0 ){
                if(mpp.count(it.first + k))cnt++;
            }
            else {
                if(it.second > 1)cnt++;
            }
        }
        return cnt;
    }
};