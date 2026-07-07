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
    int helper(TreeNode* r , int minV , int maxV){
        if(r == NULL){
            return abs(maxV-minV);
        }
        minV = min(minV , r->val);
        maxV = max(maxV , r->val);
        return max(helper(r->left , minV , maxV) , helper(r->right , minV , maxV));
    }
    int maxAncestorDiff(TreeNode* root) {
        int minV = root->val;
        int maxV = root->val;
        return helper(root , minV , maxV);
    }
};