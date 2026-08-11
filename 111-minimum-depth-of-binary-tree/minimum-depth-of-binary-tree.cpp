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
    int mini ;
    int solve(TreeNode*r ,int cnt){
        if(r == nullptr)return 0;
        if(!r->left && !r->right){
            mini = min(mini  , cnt);
            return mini;
        } 
        cnt += 1;
        solve(r->left , cnt);
        solve(r->right , cnt);
        return mini;
    }
    int minDepth(TreeNode* root) {
        if(root ==  NULL)return 0;
        if(!root->left && !root->right)return 1;
        mini = INT_MAX;
        solve(root , 1);
        return mini;
    }
};