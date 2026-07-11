class Solution {
public:
    void countLabels(unordered_map<int,vector<int>>&adj ,int curr , int parent ,  vector<int>&result , vector<int>&count , string&labels){
        char currLabel = labels[curr];
        int before = count[currLabel - 'a'];
        count[currLabel-'a'] += 1;
        for(auto child  : adj[curr]){
            if(child == parent)continue;
            countLabels(adj , child , curr , result , count , labels);
        }
        int after = count[currLabel - 'a'];
        result[curr] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n,0);
        vector<int>count(26 ,0);
        countLabels(adj , 0 , -1 ,  result , count , labels);
        return result;
    }
};