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
    long maxP = 0;
    long total_sum = 0;
    int find(TreeNode*r){
        if(r == NULL)return 0;
        int leftSum = find(r->left);
        int rightSum = find(r->right);

        int  subTreeSum = r->val + leftSum + rightSum;
        long remainingSum = total_sum - subTreeSum;

        maxP = max(maxP , subTreeSum * remainingSum);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL)return 0;
        total_sum = find(root);
        find(root);
        return ((maxP)%(1000000007));
    }
};