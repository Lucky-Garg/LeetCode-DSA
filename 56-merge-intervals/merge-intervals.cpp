class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        int strt = intervals[0][0];
        int finish = intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] <= finish){
                finish = max(intervals[i][1] , finish);
            }
            else{
                ans.push_back({strt , finish});
                strt = intervals[i][0];
                finish = intervals[i][1];
            }
        }
        ans.push_back({strt , finish});
        return ans;
    }
};