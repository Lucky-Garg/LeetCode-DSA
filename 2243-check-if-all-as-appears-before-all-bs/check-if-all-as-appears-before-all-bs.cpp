class Solution {
public:
    bool checkString(string s) {
        bool flg = true;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a' && !flg) return false;
            if(s[i] == 'b') flg = false;
        }
        return true;
    }
};