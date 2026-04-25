class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char c = x +'0';
        if(s[0] == c)return false;
        for(int i = 1 ; i<s.size() ; i++){
            if(s[i] == c)return true;
        }
        return false;
    }
};