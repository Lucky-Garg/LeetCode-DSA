class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        vector<int>inDeg(numCourses , 0);
        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
            inDeg[v]++;
        }
        vector<int>res;
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < numCourses ; i++){
            if(inDeg[i] == 0){
                q.push(i);
                cnt ++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            res.push_back(u);
            q.pop();
            for(auto v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt == numCourses){
            return res;
        }
        return {};
    }
};