class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums2[j] == nums1[i]){
                return nums1[i];
            }
            else if(nums2[j] > nums1[i]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};