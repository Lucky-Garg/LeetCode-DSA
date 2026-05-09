class Solution {
public:
    int sumEven(vector<int>&nums){
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0){
                sum += nums[i];
            }
        }
        return sum;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it : queries){
            int val = it[0];
            int idx = it[1];
            nums[idx]  = nums[idx] + val;
            ans.push_back(sumEven(nums));
        }
        return ans;
    }
};