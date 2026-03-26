class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findP(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findP(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ult_u = findP(u);
        int ult_v = findP(v);
        if (findP(ult_u) == findP(ult_v))
            return;
        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extraEdge = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findP(u) == ds.findP(v)) {
                extraEdge++;
            } else {
                ds.unionBySize(u, v);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findP(i) == i)
                cnt++;
        }
        if (extraEdge >= cnt-1)
            return cnt - 1;
        return -1;
    }
};