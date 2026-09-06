class Solution {
public:
    int adj(string s){
        int cnt = 0;
        for(int i = 0 ; i < s.size()-1 ; i++){
            if(s[i] == s[i+1])cnt++;
        }
        return cnt;
    }
    void rotate(string &s ){
        char temp = s[0];
        for(int i = 0 ; i < s.size()-1 ; i++){
            s[i] = s[i+1];
        }
        s[s.size()-1] = temp;
    }
    int countRotations(string s, int k) {
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(adj(s) == k)cnt++;
            rotate(s);
        }
        return cnt;
    }
};