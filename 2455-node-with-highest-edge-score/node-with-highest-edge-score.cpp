class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // vector<vector<int>>adj(edges.size());
        // for(int i = 0 ; i <edges.size() ; i++){
        //     adj[edges[i]].push_back(i);
        // }
        // map<int,long long>mpp;
        // for(int i = 0 ; i < edges.size();i++){
        //     for(auto it : adj[i]){
        //         mpp[i] += it;
        //     }
        // }
        // long long maxi  = -1 ;
        // for(auto it : mpp){
        //     maxi = max(maxi , it.second);
        // }
        // for(auto it : mpp){
        //     if(it.second == maxi)return it.first;
        // }
        // return -1;
        int n = edges.size();
        vector<long long >score(n,0);
        for(int i = 0 ; i<n ; i++){
            score[edges[i]] += i;
        }
        long long maxi = -1;
        int ans = 0;
        for(int i = 0; i <n ; i++){
            if(score[i] > maxi){
                maxi = score[i];
                ans = i;
            }
        }
        return ans;
    }
};