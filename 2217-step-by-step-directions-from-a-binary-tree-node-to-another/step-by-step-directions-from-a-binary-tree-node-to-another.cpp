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
    bool findPath(TreeNode* root , int target , string&path){
        if(root == NULL){
            return false;
        }
        if(root->val == target )return true;
        path.push_back('L');
        if(findPath(root->left , target , path)  == true){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right , target , path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootTosrc = "";
        string rootTodes = "";
        findPath(root , startValue , rootTosrc);
        findPath(root , destValue , rootTodes);
        cout << rootTosrc << " " << rootTodes;
        string result = "";
        int l = 0;
        while( l < rootTosrc.size() && l < rootTodes.size() && rootTosrc[l] == rootTodes[l]){
            l++;
        }

        for(int i = l ; i < rootTosrc.size() ; i++){
            result.push_back('U');
        }

        for(int i = l ; i < rootTodes.size() ;i++){
            result.push_back(rootTodes[i]);
        }

        return result;
    }
};