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
    int total;
    pair<int , int> calcSum_CntNode(TreeNode*r){
        if(r == NULL)return  {0,0};
        queue<TreeNode*>q;
        q.push(r);
        int sum = r->val;
        int cnt =1;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                cnt += 1;
                sum += curr->left->val;
            }
            if(curr->right){
                q.push(curr->right);
                cnt += 1;
                sum += curr->right->val;
            }
        }
        return {cnt , sum};
    }
    void solve(TreeNode* r){
        queue<TreeNode*>q;
        q.push(r);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            int sum = calcSum_CntNode(curr).second;
            int node = calcSum_CntNode(curr).first;
            if(sum / node == curr->val){
                total += 1;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr ->right){
                q.push(curr->right);
            }
        }
    }
    int averageOfSubtree(TreeNode* root) {
        total = 0;
        solve(root);
        return total;
    }
};