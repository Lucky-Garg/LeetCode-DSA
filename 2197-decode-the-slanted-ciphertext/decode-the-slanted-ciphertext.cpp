class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col = encodedText.size()/rows;
        vector<vector<char>>word(rows,vector<char>(col));
        int idx = 0;
        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<col ; j++){
                if(idx<encodedText.size()){
                    word[i][j] = encodedText[idx++];
                }
            }
        }
        string original = "";
        for (int startCol = 0; startCol < col; ++startCol) {
            int r = 0, c = startCol;
            while (r < rows && c < col) {
                original += word[r][c];
                r++;
                c++;
            }
        }

        while (!original.empty() && original.back() == ' ') {
            original.pop_back();
        }
        return original;
    }
};