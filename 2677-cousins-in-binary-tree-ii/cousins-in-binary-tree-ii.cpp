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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>lvlSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int currLvlSum = 0;
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                currLvlSum += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            lvlSum.push_back(currLvlSum);
        }
        root->val = 0;
        queue<TreeNode*>que;
        que.push(root);
        int idx = 1;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                TreeNode*curr = que.front();
                que.pop();

                int siblingSum = curr->left != NULL ? curr->left->val :  0;
                siblingSum += curr->right != NULL ? curr->right->val :  0;
                

                if(curr->left){
                    curr->left->val = (lvlSum[idx] - siblingSum);
                    que.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = (lvlSum[idx] - siblingSum);
                    que.push(curr->right);
                }
            }
            idx++;
        }

        return root;
    }
};