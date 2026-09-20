class Solution {
public:
    int binary(vector<vector<int>>& inter, int x) {
        int ans = inter.size();
        int lo = 0, hi = inter.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (inter[mid][0] > x) {
                ans = mid;
                hi = mid - 1;
            }

            else {
                lo = mid + 1;
            }
        }
        return ans ;
    }
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long cnt = 0;
        sort(intervals.begin() , intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            int idx = binary(intervals , intervals[i][1]);
            cnt += max(0 , idx-i-1);
        }
        return cnt;
    }
};