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
    void solve(TreeNode* r , vector<vector<int>>&ans , vector<int>temp , int x , int sum){
        if(r == NULL)return ;
        temp.push_back(r->val);
        sum += r->val;
        if(r->left == NULL && r->right == NULL){
            if(sum == x){
                ans.push_back(temp);
            }
            return;
        }
        solve(r->left , ans , temp , x , sum);
        solve(r->right , ans , temp , x , sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return {};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root , ans , temp , targetSum ,0);
        return ans;
    }
};