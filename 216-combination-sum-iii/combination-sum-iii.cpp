class Solution {
public:
    void solve(int k, int n, vector<int>& arr, vector<vector<int>>& ans,
               vector<int>& temp, int idx) {
        if (temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }
        if (temp.size() > k)
            return;
        if (idx >= arr.size())
            return;
        temp.push_back(arr[idx]);
        solve(k, n - arr[idx], arr, ans, temp, idx + 1);
        temp.pop_back();
        solve(k, n, arr, ans, temp, idx + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, arr, ans, temp, 0);
        return ans;
    }
};