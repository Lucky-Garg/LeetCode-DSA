class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        // store every element in map....
        unordered_map<int , int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        //  if the window size == size of array m
        if(k == nums.size()){
            return *max_element(nums.begin() , nums.end());
        }
        int maxi = -1;
        for(auto x : mpp){
            if(x.second == 1){
                maxi = max(maxi , x.first);
            }
        }
        if(k == 1)return maxi;
        else {
            if(nums[n-1] > nums[0]){
                if(mpp[nums[nums.size()-1]] == 1)return nums[nums.size()-1];
                else if(mpp[nums[0]] == 1)return nums[0];
            }
            else{
                if(mpp[nums[0]] == 1)return nums[0];
                else if(mpp[nums[nums.size()-1]] == 1)return nums[nums.size()-1];
            }
        }
        return -1;
    }
};