class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char , int>mpp;
        for(auto c : word){
            mpp[c] ++;
        }
        int cnt = 0;
        for(auto c : word){
            if(islower(c)){
                if(mpp.count(toupper(c))){
                    cnt++;
                    mpp.erase(c);
                    mpp.erase(toupper(c));
                }
            }
        }
        return cnt;
    }
};