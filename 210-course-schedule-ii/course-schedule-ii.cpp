class Solution {
public:
    bool dfs(int s, unordered_map<int , vector<int>>&adj , vector<int>&vis ,vector<int>&pathVis , stack<int>&st){
        vis[s] = 1;
        pathVis[s] = 1;
        for(auto v :adj[s]){
            if(!vis[v]){
                if(dfs(v , adj , vis , pathVis , st))return true;
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[s] = 0;
        st.push(s);
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>>adj;
        for(auto vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        } 
        stack<int>st;
        vector<int>vis(numCourses , 0) , pathVis(numCourses , 0);
        for(int i = 0  ; i < numCourses ; i++){
            if(!vis[i]){
                if(dfs(i , adj , vis , pathVis , st)) return {};
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};