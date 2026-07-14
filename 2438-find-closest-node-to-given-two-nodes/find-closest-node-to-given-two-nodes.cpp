class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist,
             vector<int>& vis) {
        vis[node] = 1;
        int v = edges[node];

        if (v != -1 && !vis[v]) {
            vis[v] = 1;
            dist[v] = 1 + dist[node];
            dfs(v, edges, dist, vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n , INT_MAX);
        dist1[node1] = 0;
        vector<int> dist2(n , INT_MAX);
        dist2[node2] = 0;
        vector<int> vis1(n, 0);
        vector<int> vis2(n, 0);

        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);

        int minDisNode = -1;
        int minDis = INT_MAX;

        for (int i = 0; i < n; i++) {
            int maxD = max(dist1[i], dist2[i]);
            if (minDis > maxD) {
                minDis = maxD;
                minDisNode = i;
            }
        }
        return minDisNode;
    }
};