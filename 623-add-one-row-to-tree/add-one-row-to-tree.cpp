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
    TreeNode* add(TreeNode*r , int val , int depth , int curr){
        if(r == NULL)return nullptr;
        if(curr == depth - 1){
            TreeNode* oldLeft = r->left;
            TreeNode* oldRight = r->right;

            r->left = new TreeNode(val);
            r->right = new TreeNode(val);

            r->left->left = oldLeft;
            r->right->right = oldRight;

            return r;
        }
        add(r->left , val , depth , curr+1);
        add(r->right , val , depth , curr+1);
        return r;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int curr = 1;
        return add(root , val , depth , curr);
    }
};