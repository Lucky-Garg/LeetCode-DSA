class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n) , rightSum(n);
        int sumL = 0 , sumR = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i-1 < 0){
                leftSum[i] = 0;
            }
            else{
                sumL += nums[i-1];
                leftSum[i] = sumL;
            }
            if(n-i-1+1 >=n ){
                rightSum[n-i-1] = 0;
            }
            else{
                sumR += nums[n-i] ;
                rightSum[n-i-1] = sumR;
            }
        }
        vector<int>answer(n);
        for(int i = 0 ; i<n ; i++){
            answer[i]  = abs(leftSum[i] - rightSum[i]);
        }
        return answer; 
    }
};