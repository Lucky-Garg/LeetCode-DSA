class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxDepth = 0;
        for(char c : s){
            if(c == '('){
                cnt++;
                maxDepth = max(maxDepth , cnt);
            }
            if(c == ')')
                cnt --;
        }
        return maxDepth;
    }
};