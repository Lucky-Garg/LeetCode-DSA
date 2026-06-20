class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n, '#'));
        for (int i = 0; i < m; i++) {
            grid[i][0] = '.';
        }
        for (int j = 0; j < n; j++) {
            grid[m - 1][j] = '.';
        }
        vector<string> ans;
        for (auto s : grid) {
            string temp = "";
            for (auto c : s) {
                temp += c;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};