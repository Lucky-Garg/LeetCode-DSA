class Solution {
public:
    int maxDistance(vector<int>& nums) {
        // int i = 0 , j = nums.size()-1;
        // while(i<=j){
        //     if(nums[i] != nums[j]){
        //         return abs(i-j);
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return -1;
        int mx = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                if(nums[i] != nums[j]){
                    mx = max(mx , abs(i-j));
                }
            }
        }
        return mx;
    }
};