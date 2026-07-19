/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&nums , int strt , int end){
        if(strt >= end)return NULL;
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = strt ; i < end ; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* r = new TreeNode(maxi);
        r->left = solve(nums , strt , idx );
        r->right = solve( nums , idx+1 ,end);
        return r;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums , 0 , nums.size());
    }
};