/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int time;
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& childToparent,
                    TreeNode*& r, int start, unordered_map<int, int>& vis) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            if (curr->val == start)
                r = curr;
            q.pop();
            if (curr->left) {
                childToparent[curr->left] = curr;
                vis[curr->left->val] = 0;
                q.push(curr->left);
            }
            if (curr->right) {
                childToparent[curr->right] = curr;
                vis[curr->right->val] = 0;
                q.push(curr->right);
            }
        }
    }
    void calcTime(TreeNode* r,
                  unordered_map<TreeNode*, TreeNode*>& childToparent,
                  unordered_map<int, int>& vis) {
        queue<TreeNode*> q;
        q.push(r);
        while (!q.empty()) {
            int n = q.size();
            bool flg = false;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && vis[curr->left->val] == 0) {
                    q.push(curr->left);
                    vis[curr->left->val] = 1;
                    flg = true;
                }
                if (curr->right && vis[curr->right->val] == 0) {
                    q.push(curr->right);
                    vis[curr->right->val] = 1;
                    flg = true;
                }
                if (childToparent[curr] != NULL &&
                    vis[childToparent[curr]->val] == 0) {
                    q.push(childToparent[curr]);
                    vis[childToparent[curr]->val] = 1;
                    flg = true;
                }
            }
            if (flg) {
                time += 1;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if (!root->left && !root->right)
            return 0;
        unordered_map<TreeNode*, TreeNode*> childToparent;
        childToparent[root] = nullptr;
        unordered_map<int, int> vis;
        vis[root->val] = 0;
        TreeNode* newRoot = NULL;
        markParent(root, childToparent, newRoot, start, vis);
        vis[newRoot->val] = 1;
        time = 0;
        calcTime(newRoot, childToparent, vis);
        return time;
    }
};