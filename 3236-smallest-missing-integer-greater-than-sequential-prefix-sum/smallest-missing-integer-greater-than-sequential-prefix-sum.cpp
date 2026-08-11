class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int , int>mpp;
        for(auto x : nums){
            mpp[x]++;
        }
        int sum = nums[0];
        for(int i = 1 ; i  < nums.size() ; i++){
            if(nums[i-1]+1 == nums[i]){
                sum += nums[i];
            }
            else{
                break;
            }
        }
        if(mpp.count(sum) == 0)return sum;
        while(true){
            if(mpp.count(sum) == 0)return sum;
            sum++;
        }
        return -1;
    }
};