class Solution {
public:
    int digitRange(int n){
        int minD = INT_MAX;
        int maxD = INT_MIN;
        while(n > 0){
            int digit = n%10;
            minD = min(minD , digit);
            maxD = max(maxD , digit);
            n/=10;
        }
        return maxD - minD;
    }
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto x : nums){
            mpp[x] = digitRange(x);
        }
        int maxi = INT_MIN;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        int sum = 0;
        for(auto x : nums){
            if(mpp[x] == maxi){
                sum+=x;
            }
        }
        return sum;
    }
};