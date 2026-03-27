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
        if (node == parent[node])
            return node;
        return parent[node] = findP(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ult_u = findP(u);
        int ult_v = findP(v);
        if (ult_u == ult_v)
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> merge;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (merge.find(accounts[i][j]) == merge.end()) {
                    merge[mail] = i;
                } else {
                    ds.unionBySize(i, merge[mail]);
                }
            }
        }

        vector<vector<string>> merge_mail(n);
        for (auto it : merge) {
            string mail = it.first;
            int node = ds.findP(it.second);
            merge_mail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge_mail[i].size() == 0)
                continue;
            sort(merge_mail[i].begin(), merge_mail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merge_mail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};