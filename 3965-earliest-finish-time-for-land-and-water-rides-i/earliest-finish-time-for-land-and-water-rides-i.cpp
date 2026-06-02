class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long finishLand =
                    landStartTime[i] + landDuration[i];

                long long finishBoth1 =
                    max(finishLand,
                        (long long)waterStartTime[j])
                    + waterDuration[j];

               
                long long finishWater =
                    waterStartTime[j] + waterDuration[j];

                long long finishBoth2 =
                    max(finishWater,
                        (long long)landStartTime[i])
                    + landDuration[i];

                ans = min(ans, min(finishBoth1, finishBoth2));
            }
        }

        return (int)ans;
    }
};