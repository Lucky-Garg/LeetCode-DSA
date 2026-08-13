class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int , int>mpp;
        unordered_map<int , vector<int>>adj;
        for(int i = 0 ; i < n  ; i++){
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                if(mpp.count(leftChild[i]))return false;
                mpp[leftChild[i]] = i;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                if(mpp.count(rightChild[i]))return false;
                mpp[rightChild[i]] = i;
            }
        }
        int root = -1;
        for(int i = 0 ; i < n ; i++){
            if(!mpp.count(i)){
                if(root != -1)return false;
                root = i;
            }
        }
        if(root == -1)return false;

        queue<int>q;
        q.push(root);
        vector<int>vis(n , 0);
        vis[root] = 1;
        int cnt =1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(vis[v] == 0){
                    vis[v] =1;
                    cnt += 1;
                    q.push(v);
                }
            }
        }
        return cnt == n;
    }
};