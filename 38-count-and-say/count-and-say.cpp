class Solution {
public:
    string RLE(string s){
        int i = 0;
        string result = "";
        while(i < s.size()){
            int j = i+1;
            int cnt = 1;
            while(s[j] == s[i]){
                cnt++;
                j++;
            }
            string count = to_string(cnt);
            result += count;
            result += s[i];
            i = j;
        }
        return result;
    }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        if(n > 1){
            string s = RLE(countAndSay(n-1));
            return s;
        }
        return " ";
    }
};