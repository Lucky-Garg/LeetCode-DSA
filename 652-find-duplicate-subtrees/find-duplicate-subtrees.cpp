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
    string getSubTree(TreeNode* r ,unordered_map<string , int>&mpp , vector<TreeNode*>&res){
        if(r == NULL){
            return "N";
        }

        string temp = to_string(r->val) + ',' + getSubTree(r->left , mpp , res) + ',' + getSubTree(r->right , mpp , res);

        if(mpp[temp] == 1){
            res.push_back(r);
        }
        mpp[temp] ++;
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        unordered_map<string , int>mpp;
        vector<TreeNode*>res;
        getSubTree(root , mpp , res);
        return res;   
    }
};