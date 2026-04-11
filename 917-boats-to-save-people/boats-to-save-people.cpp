class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0 , j = n-1;
        int boats  = 0;
        sort(nums.begin() , nums.end());
        while(i<=j){
            if(nums[i] + nums[j] <= limit){
                i++ , j--;
            }
            else{
                j--;
            }
            boats++;
        }
        return boats;
    }
};