class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size()-1;
        string ans = "";
        sort(strs.begin() , strs.end());
        for(int i = 0 ; i < min(strs[0].size() , strs[n].size()) ; i++){
            if(strs[0][i] != strs[n][i]) return ans;
            ans += strs[0][i];
        }
        return ans;
    }
};