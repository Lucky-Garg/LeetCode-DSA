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
    int longZigPath;
    void solve(TreeNode* r , int step , bool goLeft){
        if(r == NULL){
            return ;
        }
        longZigPath = max(longZigPath , step);
        if(goLeft){
            solve(r->left , step+1 , false);
            solve(r->right , 1 , true);
        }
        else{
            solve(r->right , step+1 , true);
            solve(r->left  , 1 , false);
        }
    }
    int longestZigZag(TreeNode* root) {
        longZigPath = -1;
        solve(root , 0,true);
        solve(root , 0,false);
        return longZigPath;
    }
};