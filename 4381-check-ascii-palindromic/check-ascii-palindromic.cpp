class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for(auto c : s){
            ans += bitset<8>(c).to_string();
        }
        string temp = ans;
        reverse(ans.begin() , ans.end());
        return temp == ans;
    }
};