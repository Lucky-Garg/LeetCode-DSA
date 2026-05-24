class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x : nums){
            mpp[x]++;
        }
        vector<int>ans;
        for(int n : nums){
            if(mpp[n] >=k){
                int temp = k;
                while(temp > 0){
                    ans.push_back(n);
                    temp--;
                }
                mpp.erase(n);
            }
            else if(mpp[n]>0){
                ans.push_back(n);
            }
        }
        return ans;
    }
};