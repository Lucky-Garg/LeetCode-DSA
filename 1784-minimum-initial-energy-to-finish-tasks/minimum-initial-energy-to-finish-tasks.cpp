class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin() , tasks.end() , [](vector<int>&a , vector<int>&b){
            return (a[1]-a[0] > b[1]-b[0]);
        });
        int curr = 0;
        int ans = 0;
        for(auto x : tasks){
            int actual = x[0];
            int mini = x[1];
            if(curr < mini){
                ans += mini-curr;
                curr = mini;
            }
            curr -= actual;
        }
        return ans;
    }
};