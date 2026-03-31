class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outD(n+1,0);
        vector<int>inD(n+1,0);
        for(auto it : trust){
            int u = it[0];
            int v = it[1];
            outD[u]++;
            inD[v]++;
        }
        for(int i = 1 ; i <=n ; i++){
            if(outD[i] == 0 && inD[i] == n-1)return i;
        }
        return -1;
        
    }
};