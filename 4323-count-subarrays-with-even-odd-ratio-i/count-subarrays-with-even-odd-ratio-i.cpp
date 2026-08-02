class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int cntValid = 0;
        for(int i = 0 ; i < n ; i++){
            int cntOdd = 0 , cntEven = 0;
            for(int j = i ; j < n ; j++){
                if(nums[j] % 2 == 0)cntEven++;
                else cntOdd++;
                if(cntOdd > 0 && ((double(cntEven) / double(cntOdd)) <= (double(a)/double(b)))) cntValid ++;
            }
        }
        return cntValid;
    }
};