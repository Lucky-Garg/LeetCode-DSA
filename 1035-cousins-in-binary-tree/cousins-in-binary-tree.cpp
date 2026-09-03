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
    void bfs(unordered_map<int , int>&mpp , TreeNode* root , vector<vector<int>>&lvl){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    mpp[curr->left->val] = curr->val;
                    q.push(curr->left);
                }
                if(curr->right){
                    mpp[curr->right->val] = curr->val;
                    q.push(curr->right); 
                }
            }
            lvl.push_back(temp);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>>lvl;
        unordered_map<int , int>childToParent;
        childToParent[root->val] = -1;
        bfs(childToParent , root , lvl);
        for(auto v : lvl){
            bool check1 = false, check2 = false;
            for(auto i : v){
               if(i == x)check1 = true;
               if(i == y)check2 = true;
            }
            if(check1 && check2){
                if(childToParent[x] != childToParent[y])return true;
            }
        }
        return false;
    }
};