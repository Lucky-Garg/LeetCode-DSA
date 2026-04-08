class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        for(auto it : queries){
            int idx = it[0];
            long long multi = it[3];
            while(idx <= it[1]){
                long  long x = (nums[idx] * multi) % mod;
                nums[idx] = int(x);
                idx += it[2];
            }
        }
        int XOR  = 0;
        for(auto it : nums){
            XOR ^= it;
        }
        return XOR;
    }
};