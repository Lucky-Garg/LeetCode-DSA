class Solution {
public:
    typedef long long ll;
    bool check(int mid , int n , long long  k , unordered_map<int , vector<pair<int ,int>>>&adj){
        vector<long long>result(n , LLONG_MAX);
        result[0] = 0;
        priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            ll d = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            if(d > k)return false;
            if(node == n-1)return true;
            if(result[node] < d)continue;

            for(auto v : adj[node]){
                int nghr = v.first;
                int cost = v.second;

                if(cost < mid) continue;

                if(result[nghr] > cost + d){
                    result[nghr] = cost + d;
                    pq.push({cost+d , nghr});
                }
            }
        }
        return false;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        unordered_map<int , vector<pair<int ,int>>>adj;
        int l = INT_MAX , h = 0;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            if(!online[u] || !online[v]){
                continue;
            }

            adj[u].push_back({v , w});

            l = min(l , w);
            h = max(h , w);
        }

        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(mid , n , k , adj)){
                ans = mid;
                l = mid+1;
            }
            else{
                h =  mid-1;
            }
        }
        return ans;

    }
};