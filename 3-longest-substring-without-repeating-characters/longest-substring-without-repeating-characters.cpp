class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j = 0;
        unordered_map<char , int>mpp;
        int maxLen = 0;
        while(j < s.size()){
            while(mpp.count(s[j])){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i++]);
                }
            }
            mpp[s[j]]++;
            maxLen = max(maxLen , j-i+1);
            j++;
        }
        return maxLen;
    }
};