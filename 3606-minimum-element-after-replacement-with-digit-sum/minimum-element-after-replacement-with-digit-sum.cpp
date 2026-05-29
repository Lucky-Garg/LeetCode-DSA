class Solution {
public:
    int sumD(int n){
        int s = 0;
        while(n>0){
            s += n%10;
            n/=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            nums[i] = sumD(nums[i]);
        }
        return *min_element(nums.begin() , nums.end());
    }
};