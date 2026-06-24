class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ;i < nums2.size() ; i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin() , nums1.end());
        double ans = 0;
        if(nums1.size() % 2 == 0){
            int idx = nums1.size()/2;
            ans = ((nums1[idx]+nums1[idx-1])/2.0);
            return ans;
        }
        return double(nums1[nums1.size()/2]);
        
    }
};