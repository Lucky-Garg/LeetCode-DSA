class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        while(i<n){
            nums[i++] = 0;
        }
    }
};