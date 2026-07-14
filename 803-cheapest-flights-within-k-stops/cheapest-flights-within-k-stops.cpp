class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int , vector<pair<int , int >>>adj;
        for(auto vec : flights){
            int u  = vec[0];
            int v  = vec[1];
            int d  = vec[2];
            adj[u].push_back({v , d});
        }
        vector<int>dis(n, INT_MAX);
        dis[src] = 0;
        queue<pair<int , int>>q;
        q.push({src , 0});
        int step = 0;
        while(!q.empty() && step <= k){
            int qSize = q.size();
            for(int i = 0 ; i < qSize ; i++){
                int node = q.front().first;
                int currDis = q.front().second;
                q.pop();
                for(auto v : adj[node]){
                    int node = v.first;
                    int nodeDis = v.second;
                    if(dis[node] > currDis + nodeDis){
                        dis[node] = currDis + nodeDis;
                        q.push({node , dis[node]});
                    }
                }
            }
            step ++;
        }
        return (dis[dst] == INT_MAX) ? -1 : dis[dst];
    }
};