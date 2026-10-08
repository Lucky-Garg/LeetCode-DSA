class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string finalStr = "" ;
        int openCnt = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                openCnt++;
                if(openCnt > 1)ans+=s[i];
            }
            if(s[i] == ')'){
                if(openCnt >1){
                    ans+=s[i];
                }
                openCnt--;
            }
            if(openCnt == 1){
                finalStr += ans;
                ans = "";
            }

        }
        return finalStr;
    }
};