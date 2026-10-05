class Solution {
public:
    int scoreOfParentheses(string s) {
        int openCnt = 0 , score = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                openCnt++;
            }
            if(s[i] == ')'){
                openCnt--;
                if(s[i-1] == '('){
                    score += pow(2 , openCnt);
                }
            
            }
        }
        return score;
    }
};