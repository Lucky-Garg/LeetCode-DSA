class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char , int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        set<pair<char,char>>st;
        int sum = 0;
        for(auto it : s){
            char c = it;
            char m;
            if(isalpha(c)){
                m ='a' + ('z' - c);
            }
            else{
                m = '0'+('9'-c);
            }
            if(st.count({c,m}) || st.count({m,c}))continue;
        
            sum += abs(mpp[c]-mpp[m]);
            st.insert({c,m});
            st.insert({m,c});
        }
        return sum;
    }
};