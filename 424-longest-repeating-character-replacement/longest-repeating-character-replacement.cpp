class Solution {
public:
    int findMax(unordered_map<char , int>mpp){
        int maxi = 0;
        for(auto x : mpp){
            maxi = max(maxi , x.second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int l = 0 , r = 0;
        int maxLen =0 , maxFreq = 0;
        unordered_map<char , int>mpp;
        while(r < s.size()){
            mpp[s[r]]++;
            maxFreq = max(findMax(mpp) , maxFreq);
            if((r-l+1) - maxFreq > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)mpp.erase(s[l]);
                l++;
            }
            else{
                maxLen = max(maxLen , (r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};