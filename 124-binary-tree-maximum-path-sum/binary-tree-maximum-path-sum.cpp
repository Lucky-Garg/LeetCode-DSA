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
    int maxSum ;
    int solve(TreeNode* root){
        if(root == NULL)return 0;

        int l  = solve(root->left);
        int r  = solve(root->right);

        int only_root = root->val;
        int either_from_one = max(l , r) + root->val;
        int both = l + r + root->val;
    
        maxSum = max({maxSum , only_root , either_from_one , both});

        return max(only_root , either_from_one);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};