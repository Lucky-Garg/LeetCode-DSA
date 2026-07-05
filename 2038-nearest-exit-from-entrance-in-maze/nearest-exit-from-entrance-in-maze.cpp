class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int lvl = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (!(r == entrance[0] && c == entrance[1] )&&
                      (r == 0 || r == row - 1 || c == 0 || c == col - 1)) {
                    return lvl;
                }
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col ||
                        maze[nr][nc] == '+') {
                        continue;
                    } else {
                        q.push({nr, nc});
                        maze[nr][nc] = '+';
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};