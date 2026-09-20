class Solution {
public:
    int reverseDegree(string s) {
        int pro = 0;
        for(int i = 0 ; i < s.size() ; i++){
            pro +=  ('z'-s[i]+1)*(i+1);
        }
        return pro;
    }
};