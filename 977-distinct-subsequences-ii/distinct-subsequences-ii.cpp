class Solution {
public:
    vector<int>prev;
    int m = 1e9+7;
    int dp[2001];
    int solve(int n){
        if(n == 0)return 1;
        if(dp[n] != -1)return dp[n];
        int total = (2*solve(n-1))%m;

        if(prev[n] != 0){
            int dup = solve(prev[n]-1);
            total= (total - dup + m)%m;
        }
        return dp[n] = total%m;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        if(n == 1)return 1;
        prev.assign(n+1 , 0);
        memset(dp ,-1 , sizeof(dp));
        vector<int>lastSeen(26 , 0);
        for(int i = 1 ; i <=n ; i++){
            int idx  = s[i-1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n)-1 + m)%m;
    }
};