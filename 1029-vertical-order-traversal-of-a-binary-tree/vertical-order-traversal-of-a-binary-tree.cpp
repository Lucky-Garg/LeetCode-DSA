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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        map<int , map<int , multiset<int>>>store;

        queue<pair<TreeNode* , pair<int , int>>>q;

        q.push({root , {0 , 0}});

        while(!q.empty()){
            auto p = q.front();
            TreeNode* node = p.first;
            int vd = p.second.first;
            int lvl = p.second.second;

            q.pop();

            store[vd][lvl].insert(node->val);
            if(node->left){
                q.push({node->left ,{vd-1 , lvl+1}});
            }

            if(node->right){
                q.push({node->right , {vd+1 , lvl+1}});
            }
        }

        for(auto x : store){
            vector<int>v;
            for(auto ele : x.second){
                v.insert(v.end() ,ele.second.begin(), ele.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};