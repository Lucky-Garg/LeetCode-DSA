class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>ans(n);
        for(int i = 0 ; i<matrix.size() ; i++){
            int cnt = 0;
            for(auto it : matrix[i]){
                if(it == 1)cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};