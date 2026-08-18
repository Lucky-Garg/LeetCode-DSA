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
    string result ;
    void solve(TreeNode* r , string curr){
        if(!r)return;

        curr =  char(r->val + 'a') + curr;

        if(!r->left && !r->right){
            if(result == "" || result > curr){
                result = curr;
            }
            return;
        }

        solve(r->left ,curr);
        solve(r->right , curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        result = "";
        solve(root , "");
        return result;
    }
};