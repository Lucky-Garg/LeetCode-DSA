class Solution {
public:
    int digitSum(int n){
        int s = 0;
        while(n){
            s += n%10;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>nonSorted = nums;
        unordered_map<int , int>mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]] = i;
        }
        sort(nums.begin() , nums.end() , [&](int a , int b){
            if(digitSum(a) == digitSum(b)){
                return a < b;
            }
            return digitSum(a) < digitSum(b);
        });
        int swapCnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int expEle = nums[i];
            int currEle = nonSorted[i];

            if(currEle == expEle) continue;
            int idx = mpp[expEle];
            swap(nonSorted[i] , nonSorted[idx]);
            mpp[expEle] = i;
            mpp[currEle] = idx;
            swapCnt++;
        }
        return swapCnt;
        

    }
};