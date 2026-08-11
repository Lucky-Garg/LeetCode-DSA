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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode* , int >>q;
        int maxSum = INT_MIN;
        int ans = -1;
        q.push({root , 1});
        while(!q.empty()){
            int n = q.size();
            int lvl = q.front().second;
            int sum = 0;
            for(int i = 0 ; i  < n ; i++){
                TreeNode* curr = q.front().first;
                q.pop();
                sum += curr->val;
                if(curr -> left){
                    q.push({curr->left , lvl+1});
                }
                if(curr -> right){
                    q.push({curr->right , lvl+1});
                }
            }
            if(maxSum < sum){
                maxSum = sum;
                ans = lvl;
            }
        }
        return ans;
    }
};