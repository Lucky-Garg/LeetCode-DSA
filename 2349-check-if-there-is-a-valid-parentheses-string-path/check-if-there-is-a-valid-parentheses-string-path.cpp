class Solution {
public:
    bool solve(vector<vector<char>>& grid , int i  , int j , int openCnt , vector<vector<vector<int>>>&dp){
        if(i >= grid.size() || j >= grid[0].size()) return false;


        if(grid[i][j] == '(') openCnt += 1;
        else{
            openCnt -= 1;
        }


        if(openCnt < 0) return false;

        if(dp[i][j][openCnt] != -1) return dp[i][j][openCnt] ;
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return dp[i][j][openCnt] =  (openCnt == 0);
        }
        return dp[i][j][openCnt] = solve(grid , i+1 , j , openCnt ,dp ) || solve(grid , i , j+1 , openCnt , dp);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return false;
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(m+1  , vector<int>(n+m , -1)));
        return solve(grid , 0 , 0 ,  0 , dp);
    }
};