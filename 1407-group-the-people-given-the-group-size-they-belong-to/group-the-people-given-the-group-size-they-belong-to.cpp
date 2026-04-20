class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        vector<vector<int>>ans;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it : mpp){
            auto temp = it.second;
            vector<int>T;
            for(int i = 0 ; i <temp.size() ; i++){
                T.push_back(temp[i]);
                if(T.size() == it.first){
                    ans.push_back(T);
                    T.clear();
                }
            }

        }
        return ans;
    }
};