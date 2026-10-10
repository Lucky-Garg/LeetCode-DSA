class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int k = k1+k2;
        vector<int>diff(1e5+1 , 0);
        for(int i = 0 ; i < nums1.size() ;i++){
            diff[abs(nums1[i] - nums2[i])] ++;
        }
        for(int i = 1e5 ; i > 0 && k > 0 ; i--){
            int currOp = min(diff[i] , k);
            diff[i] -= currOp;
            diff[i-1] += currOp;
            k -= currOp;
        }
        long long ans = 0;
        for(int i = 1 ; i <= 1e5 ; i++){
            long long d = i;
            ans += diff[i]*(d*d);
        }
        return ans;
    }
};