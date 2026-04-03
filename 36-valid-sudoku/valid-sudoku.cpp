class Solution {
public:
    bool safe(vector<vector<char>>& board , int r , int c , char digit){
        int n = board.size();
        for(int i = 0 ; i< n ; i++){
            if(i == c)continue;
            if(board[r][i] == digit)return false;
        }
        for(int j = 0 ; j<n ; j++){
            if(j == r)continue;
            if(board[j][c] == digit)return false;
        }
        
        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i = sr ; i<=sr+2 ; i++){
            for(int j = sc ; j<=sc+2 ; j++){
                if(i == r && j == c)continue;
                if(board[i][j] == digit)return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j] != '.'){
                    if(safe(board , i , j , board[i][j]) == false)return false;
                }
            }
        }
        return true;
    }
};