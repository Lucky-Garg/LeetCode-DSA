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
    long long maxWidth ;
    void solve(TreeNode* r){
        queue<pair < TreeNode* , long long>>q;
        q.push({r , 0});
        while(!q.empty()){
            long long n = q.size();
            long long L = q.front().second;
            long long R = q.back().second;
            maxWidth = max(maxWidth , R-L+1 );
            for(long long i = 0 ; i < n ; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                idx = idx-L;
                if(node->left){
                    q.push({node->left , 2*idx+1});
                }
                if(node->right){
                    q.push({node->right , 2*idx+2});
                }
            }
        }

    }
    int widthOfBinaryTree(TreeNode* root) {
        maxWidth = -1;
        solve(root);
        return maxWidth ;
    }
};