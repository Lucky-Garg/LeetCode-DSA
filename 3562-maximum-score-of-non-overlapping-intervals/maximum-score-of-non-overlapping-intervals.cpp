class Solution {
public:
    int n ;
    vector<int>nextIdx;
    struct Node {
        long long score = -1;
        vector<int>idxs;
    };

    Node solve(vector<vector<int>>& intervals , int i , int k , vector<vector<Node>>&dp){
        if(k == 0 || i == n){
            Node base;
            base.score = 0;
            return base;
        }
        if(dp[i][k].score != -1)return dp[i][k];

        Node skip = solve(intervals , i+1 , k , dp);

        long long wt = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIdx[i];

        Node temp = solve(intervals , j , k-1 , dp);

        Node take;
        take.score = temp.score + wt;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        sort(begin(take.idxs) , end(take.idxs));

        Node result ;
        if(skip.score > take.score){
            result = skip;
        }
        else if(skip.score < take.score){
            result = take;
        }
        else{
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[i][k]=result;
    }
    int findIdx(vector<vector<int>>& intervals , int x){
        int l = 0 , h = n-1;
        int result = n;
        while(l <= h){
            int mid = (l+h)/2;
            if(intervals[mid][0] > x){
                result = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        nextIdx.assign(n , -1);
        vector<vector<Node>>dp(n , vector<Node>(5));
        for(int i = 0 ; i < n ; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin() , intervals.end());

        for(int i = 0 ; i < n ; i++){
            int endPoint = intervals[i][1];

            nextIdx[i] = findIdx(intervals , endPoint);
        }

        int k  = 4;
        return solve(intervals , 0 , k , dp).idxs;
    }
};