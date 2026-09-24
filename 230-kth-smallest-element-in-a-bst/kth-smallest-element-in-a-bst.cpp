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
    int ans ;
    void solve(TreeNode* root , int &k){
        if(root == NULL) return;

        solve(root->left , k);
        if(k == 1){
            if(ans == -1)ans = root->val;
        }
        k-=1;
        solve(root ->right , k);
    }
    int kthSmallest(TreeNode* root, int k) {

        ans = -1;
        solve(root , k);
        return ans ;
    }
};