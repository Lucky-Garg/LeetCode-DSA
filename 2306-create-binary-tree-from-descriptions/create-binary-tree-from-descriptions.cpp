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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int>parent , child ;
        unordered_map<int,vector<pair<int,int>>>parentToChild;
        for(auto v : descriptions){
            int p = v[0] , c = v[1] , isLeft = v[2];
            parent.insert(p);
            child.insert(c);
            parentToChild[p].push_back({c , isLeft});
        }
        int rootParent = 0;
        for(auto s : parent){
            if(!child.count(s)){
                rootParent = s;
                break;
            }
        }
        TreeNode*root = new TreeNode(rootParent);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            for(auto cI : parentToChild[p->val]){
                int childValue = cI.first ;
                int isLeft = cI.second;
                TreeNode* child = new TreeNode(childValue);
                q.push(child);
                if(isLeft){
                    p->left = child;
                }
                else{
                    p->right = child;
                }
            }
        }
        return root;
    }
};