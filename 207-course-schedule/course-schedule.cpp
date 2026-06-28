class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        vector<int>inDegree(numCourses , 0);
        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < numCourses ; i++){
            if(inDegree[i] == 0){
                q.push(i);
                cnt ++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt == numCourses)return true;
        return false;

    }
};