class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0 , j = 0;
        unordered_map<char ,int>mpp;
        int ans = 0;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]] > 2){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)mpp.erase(s[i]);
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};