/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root== nullptr)return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>store;

        while(!q.empty()){
            int n = q.size();

            vector<int>temp;
            while(n--){
                Node* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for(auto v : curr->children){
                    q.push(v);
                }
            }
            store.push_back(temp);
        }
        return store;
    }
};