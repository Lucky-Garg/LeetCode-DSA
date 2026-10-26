class Solution {
public:
    int n , m;
    long long dfs(vector<vector<int>>& grid , int i , int j){
        if(i < 0 || i >= n || j < 0 || j>= m || grid[i][j] == 0){
            return 0;
        }
        long long val = grid[i][j];
        grid[i][j] = 0;
        long long left = dfs(grid , i , j-1);
        long long right = dfs(grid , i , j+1);
        long long up = dfs(grid , i-1 , j);
        long long down = dfs(grid , i+1 , j);

        return val + left + right + up + down;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int islandCnt = 0;
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0){
                    if(dfs(grid , i , j) % k == 0){
                        islandCnt ++;
                    }
                }
            }
        }
        return islandCnt;
    }
};