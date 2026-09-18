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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>lvls;
        if(!root)return lvls;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToright = true;

        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(leftToright){
                lvls.push_back(temp);
            }
            else{
                reverse(temp.begin() , temp.end());
                lvls.push_back(temp);
            }
            leftToright = !leftToright;
        }
        return lvls;
    }
};