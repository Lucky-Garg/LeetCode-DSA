class Solution {
public:
    int robT(vector<int>& nums){
        int curr = 0 ;
        int prev2 = nums[0];
        int prev1 = max(nums[0] , nums[1]);
        for(int i =2  ; i < nums.size() ; i++){
            curr = max(nums[i] + prev2 , prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2){
            return max(nums[0] , nums[1]);
        }
        vector<int>first , second;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(i == 0){
                first.push_back(nums[i]);
            }
            else if( i == n-1){
                second.push_back(nums[i]);
            }
            else{
                first.push_back(nums[i]);
                second.push_back(nums[i]);
            }
        }
        return max(robT(first), robT(second));
    }
};