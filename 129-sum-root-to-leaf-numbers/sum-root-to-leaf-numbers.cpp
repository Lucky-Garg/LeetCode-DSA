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
    int sum ;
    int solve(TreeNode*root , int num){
        if(root == NULL){
           return 0;
        }
        num = num*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum += num;
        }
        solve(root -> left , num);
        solve(root->right , num);
        num = num/10;
        return num;
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        solve(root , 0);
        return sum;
    }
};