class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin() , nums.end(), [&](int a , int b){
            if(__builtin_popcount(a) != __builtin_popcount(b)){
                return __builtin_popcount(a) < __builtin_popcount(b);
            }
            else return a < b;
        });
        return nums;
    }
};