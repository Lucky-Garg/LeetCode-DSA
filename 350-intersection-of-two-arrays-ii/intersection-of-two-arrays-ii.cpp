class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp1 , mpp2;
        vector<int>ans;
        for(auto it : nums1){
            mpp1[it]++;
        }
        for(auto it : nums2){
            mpp2[it]++;
        }
        for(int x : nums2){
            if(mpp1.count(x)){
                int num = mpp1[x]>mpp2[x] ? mpp2[x] : mpp1[x];
                while(num>0){
                    ans.push_back(x);
                    num--;
                    mpp1[x]-- , mpp2[x]--;
                }
            }
        }
        return ans;
    }
};