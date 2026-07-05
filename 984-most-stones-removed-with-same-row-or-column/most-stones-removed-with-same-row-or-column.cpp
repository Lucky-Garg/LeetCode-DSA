class Solution {
public:
    void dfs(vector<vector<int>>& stones, int idx, vector<int>& vis) {
        vis[idx] = 1;
        for (int i = 0; i < stones.size(); i++) {
            int r = stones[idx][0];
            int c = stones[idx][1];
            if (!vis[i] && (stones[i][0] == r || stones[i][1] == c)) {
                dfs(stones, i, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                group++;
                dfs(stones, i, vis);
            }
        }
        return n - group;
    }
};