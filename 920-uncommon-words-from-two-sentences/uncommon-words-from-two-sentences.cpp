class Solution {
public:
    void constructString(vector<string>&sent , string &s){
        string temp = "";
        for(auto c :s){
            if(isspace(c)){
                sent.push_back(temp);
                temp  = "";
            }
            else{
                temp += c;
            }
        }
        sent.push_back(temp);
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        vector<string>sent1 , sent2;
        constructString(sent1 , s1);
        constructString(sent2 , s2);
        unordered_map<string , int>mpp1 , mpp2;
        for(auto w : sent1){
            mpp1[w]++;
        }
        for(auto w : sent2){
            mpp2[w]++;
        }
        for(auto x : mpp1){
            if(x.second == 1 && mpp2.count(x.first) == 0){
                ans.push_back(x.first);
            }
        }
        for(auto x : mpp2){
            if(x.second == 1 && mpp1.count(x.first) == 0){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};