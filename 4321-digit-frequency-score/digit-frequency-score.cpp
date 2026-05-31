class Solution {
public:
    void storeD(int n , unordered_map<int,int>&mpp){
        while(n>0){
            int d = n%10;
            mpp[d]++;
            n /= 10;
        }
    }
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mpp;
        storeD(n , mpp);
        int ans = 0;
        for(auto x : mpp){
            ans += x.first * x.second;
        }
        return ans;
    }
};