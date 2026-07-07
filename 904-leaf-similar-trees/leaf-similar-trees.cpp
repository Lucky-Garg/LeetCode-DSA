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
    void leaf(TreeNode*r , vector<int>&store){
        if(r == NULL)return ;
        if(r->left == NULL && r->right == NULL){
            store.push_back(r->val);
            return ;
        }
        leaf(r->left , store);
        leaf(r->right , store);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1 , ans2;
        leaf(root1 , ans1);
        leaf(root2 , ans2);
        return ans1 == ans2;
    }
};