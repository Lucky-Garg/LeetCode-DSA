class Solution {
public:
    void dfs(int s, unordered_map<int, vector<int>>& adj, vector<int>& vis) {
        vis[s] = 1;
        for (auto v : adj[s]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
    bool check(int s, unordered_map<int, vector<int>>& adj, vector<int>& vis){
        for(auto v : adj[s]){
            if(vis[v] == 1)return true;
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);
        bool flg = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (check(i, adj, vis)) {
                    flg = true;
                }
            }
        }
        if (!flg) {
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    ans.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};