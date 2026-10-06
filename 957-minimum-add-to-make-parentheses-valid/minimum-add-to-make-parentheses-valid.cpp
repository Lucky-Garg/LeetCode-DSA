class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0 , minMove = 0;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '('){
                cnt++;
            }
            if(cnt >0  && s[i] == ')')cnt--;
            else if(cnt <=0 && s[i] == ')')minMove++;
        }
        return abs(cnt + minMove);
    }
};