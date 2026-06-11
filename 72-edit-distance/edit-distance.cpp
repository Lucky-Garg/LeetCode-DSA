class Solution {
public:
    // int fun(string word1, string word2, int i, int j) {
    //     if (i < 0)
    //         return j + 1;
    //     if (j < 0)
    //         return i + 1;
    //     if (word1[i] == word2[j]) {
    //         return fun(word1, word2, i - 1, j - 1);
    //     } else {
    //         int I = 1 + fun(word1, word2, i, j - 1);
    //         int D = 1 + fun(word1, word2, i - 1, j);
    //         int R = 1 + fun(word1, word2, i - 1, j - 1);
    //         return min((I,D), R);
    //     }
    // }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1));
        for(int i = 0 ; i <= n ;i++){
            dp[i][0] = i;
        }
        for(int j = 0 ; j <= m ; j++){
            dp[0][j] = j;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int I = 1 + dp[i][j-1];
                    int D = 1 + dp[i-1][j];
                    int R = 1 + dp[i-1][j-1];
                    dp[i][j] =  min({I,D,R});
                }
            }
        }
        return dp[n][m];
    }
};