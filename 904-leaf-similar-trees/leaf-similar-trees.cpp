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
    void leaf(TreeNode*r , string&s){
        if(r == NULL)return ;
        if(r->left == NULL && r->right == NULL){
            s += to_string(r->val)+"_";
            return ;
        }
        leaf(r->left , s);
        leaf(r->right , s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string ans1 , ans2;
        leaf(root1 , ans1);
        leaf(root2 , ans2);
        cout << ans1 << " " << ans2;
        return ans1 == ans2;
    }
};