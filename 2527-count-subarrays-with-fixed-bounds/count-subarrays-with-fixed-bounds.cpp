class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minIdx = -1;
        int maxIdx = -1;
        int culIdx = -1;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culIdx = i;
            }
            if(nums[i] == minK){
                minIdx = i;
            }
            if(nums[i] == maxK){
                maxIdx = i;
            }
            long long smaller = min(minIdx , maxIdx);
            long long temp  = smaller - culIdx;
            ans += (temp<=0) ? 0 : temp; 
        }
        return ans;
    }
};