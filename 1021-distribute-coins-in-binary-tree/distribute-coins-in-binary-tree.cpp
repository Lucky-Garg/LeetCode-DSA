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
    int moves ;
    int solve(TreeNode* r){
        if(r == NULL)return 0;

        int l = solve(r->left);
        int rt = solve(r->right);

        moves += abs(l) + abs(rt) ;
        return (l+rt+r->val)-1;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        solve(root);
        return moves;
    }
};