class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int peak;
        for(int i = 1 ; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                peak = i;
                break;
            }
        }
        long long sumL = 0 , sumR = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if( i <= peak){
                sumL += nums[i];
            }
            if( i>= peak){
                sumR += nums[i];
            }
        }
        if(sumL == sumR)return -1;
        return (sumL > sumR) ? 0 : 1;
    }
};