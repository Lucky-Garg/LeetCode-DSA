class Solution {
public:
    bool isSafe(vector<vector<char>>& board , int row , int col , int digit){
        for(int i = 0 ; i<9 ; i++){
            if(board[row][i]  == digit)return false;
        }

        for(int i = 0 ; i<9 ; i++){
            if(board[i][col] == digit)return false;
        }

        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i = sr ; i<=sr+2 ; i++){
            for(int j = sc ; j<=sc+2 ; j++){
                if(board[i][j] == digit)return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board , int row , int col){
        if(row == 9){
            return true;
        }
        int nextRow = row , nextCol = col+1;
        if(nextCol == 9){
            nextRow = nextRow + 1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return helper(board , nextRow , nextCol);
        }
        for(char i = '1'  ; i <= '9' ; i++){
            if(isSafe(board , row , col , i)){
                board[row][col] = i;
                if(helper(board , nextRow , nextCol))return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board , 0 , 0);
    }
};