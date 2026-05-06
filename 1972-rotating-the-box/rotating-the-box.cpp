class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>box( m , vector<char>(n));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j < m ; j++){
                box[j][n-i-1] = boxGrid[i][j];
            }
        }
        for(int j = 0 ; j < n ; j++){
            int eR = m-1;
            for(int i = m-1 ; i>=0 ; i--){
                if(box[i][j] == '*'){
                    eR = i-1;
                }
                else if(box[i][j] == '#'){
                    swap(box[i][j] , box[eR][j]);
                    eR--;
                }
            }
        }
        return box;
    }
};