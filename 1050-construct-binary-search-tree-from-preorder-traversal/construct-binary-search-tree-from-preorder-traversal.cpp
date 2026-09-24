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
    TreeNode* build(TreeNode* root , vector<int>&preorder , int idx){
        if(!root){
            return new TreeNode(preorder[idx]);
        }
        if(preorder[idx] > root->val){

            root->right = build(root->right , preorder , idx);
        }
        else{
            root->left = build(root->left , preorder , idx);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1 ; i < preorder.size() ; i++){
            build(root , preorder , i);
        }
        return root;
    }
};