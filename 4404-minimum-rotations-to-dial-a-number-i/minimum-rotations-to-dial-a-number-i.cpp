class Solution {
public:
    int minRotations(string s) {
        int step = 0 , pointer = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int num = s[i]-'0';
            int d = abs(pointer - num);
            step += min(d , 10-d);
            pointer = num;
        }
        return step;
    }
};