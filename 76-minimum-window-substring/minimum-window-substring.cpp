class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        unordered_map<char , int>mpp;
        for(auto c : t){
            mpp[c] ++;
        }
        int i = 0 , j = 0;
        int cnt = t.size();
        int strt_idx = 0;
        int minWinSize = INT_MAX;
        while(j < s.size()){
            if(mpp[s[j]] > 0){
                cnt --;
            }
            mpp[s[j]]--;
            while(cnt == 0){
                int currSize = j-i+1;
                if(minWinSize > currSize){
                    minWinSize = currSize;
                    strt_idx = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0){
                    cnt++;
                }
                i++;
            }
            j++;
        }
        return (minWinSize == INT_MAX) ? "" : s.substr(strt_idx , minWinSize);
    }
};