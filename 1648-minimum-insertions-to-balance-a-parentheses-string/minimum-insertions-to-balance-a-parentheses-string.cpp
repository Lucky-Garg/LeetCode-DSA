class Solution {
public:
    int minInsertions(string s) {
        int openCnt = 0 ;
        int min_insert = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                openCnt ++;
                i++;
            }
            else{
                if(openCnt > 0){
                    openCnt--;
                }
                else{
                    min_insert ++;
                }

                if(i + 1 < s.size() && s[i+1] == ')'){
                    i+=2;
                }
                else{
                    min_insert ++;
                    i++;
                }

            }
        }
        return min_insert + 2*openCnt;

        
    }
};