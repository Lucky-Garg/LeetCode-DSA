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
    int cntP;
    void createGraph(TreeNode* root , unordered_map<TreeNode* , vector<TreeNode*>>&adj ,unordered_set<TreeNode*>&st){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(!curr->left && !curr->right){
                st.insert(curr);
            }
            q.pop();
            if(curr->left){
                adj[curr].push_back(curr->left);
                adj[curr->left].push_back(curr);
                q.push(curr->left);
            }
            if(curr->right){
                adj[curr].push_back(curr->right);
                adj[curr->right].push_back(curr);
                q.push(curr->right);
            }
        }
    }
    int countPairs(TreeNode* root, int distance) {
        cntP = 0;
        unordered_set<TreeNode*>st;
        unordered_map<TreeNode* , vector<TreeNode*>>adj;

        createGraph(root , adj , st);

        for(auto x : st){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>vis;
            q.push(x);
            vis.insert(x);

            for(int lvl = 0 ; lvl <= distance ; lvl++){
                int n = q.size();
                while(n--){
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != x && st.count(curr)){
                        cntP+=1;
                    }

                    for(auto v : adj[curr]){
                        if(!vis.count(v)){
                            q.push(v);
                            vis.insert(v);
                        }
                    }
                }
            }
        }
        return cntP/2;

    }
};