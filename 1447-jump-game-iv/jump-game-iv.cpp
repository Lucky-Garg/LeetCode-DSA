class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , vector<int>>mpp;
        for(int i = 0 ; i<n ; i++){
            mpp[arr[i]].push_back(i);
        }
        vector<int>vis(n , 0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i<size ; i++){
                int idx = q.front();
                q.pop();
                if(idx == n-1)return steps;
                int left = idx - 1;
                int right = idx + 1;
                if(left >= 0 && !vis[left]){
                    q.push(left);
                    vis[left] = 1;
                }
                if(right <= n-1 && !vis[right]){
                    q.push(right);
                    vis[right] = 1;
                }
                for(auto x : mpp[arr[idx]]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                }
                mpp.erase(arr[idx]);
            }
            steps++;
        }
        return -1;
    }
};