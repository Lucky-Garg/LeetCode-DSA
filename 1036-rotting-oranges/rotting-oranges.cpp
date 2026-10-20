class Solution {
public:
    int n , m;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        queue<pair<int, int>>q;
        int dr[4] = {-1 , 1 , 0 , 0};
        int dc[4] = {0 , 0 , -1 , 1};

        int fresh = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minCnt = 0;
        while(!q.empty() && fresh){
            int sz = q.size();
            while(sz--){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();
                for(int i = 0 ; i <4 ; i++){
                    int nr = dr[i] + row;
                    int nc = dc[i] + col;

                    if(nr >= 0 && nr < n && nc>=0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minCnt++;
        }
        return fresh == 0 ? minCnt : -1;
    }
};