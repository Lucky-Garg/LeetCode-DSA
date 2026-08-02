class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = -1;
        for(int i = 0 ; i< nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(i!=j){
                    long long strength = ((long long)nums[i] * (long long)nums[j]) / pow(gcd(nums[i] , nums[j]) , 2);
                    if(ans < strength){
                        ans = strength;
                    }
                }
            }
        }
        return ans;
    }
};