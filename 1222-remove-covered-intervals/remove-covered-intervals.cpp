class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        for(int i = 0 ; i < intervals.size(); i++){
            for(int j = 0 ; j < intervals.size() ; j++){
                if(i!=j){
                    if(intervals[j][0] == -1 && intervals[j][1] == -1)continue;
                    if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]){
                        intervals[j] = {-1,-1};
                        cnt++;
                    }
                }
            }
        }
        return intervals.size()-cnt;
    }
};