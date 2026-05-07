class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string>word;
        int n = paragraph.size();
        string temp = "";
        if(isalpha(paragraph[n-1])){
            for(auto c : paragraph){
                if(!isalpha(c)){
                    if(isalpha(temp[0])) word.push_back(temp);
                    temp = "";
                    continue;
                }
                temp += tolower(c);
            }
            word.push_back(temp);
        }
        else{
            for(auto c : paragraph){
                if(!isalpha(c)){
                    if(isalpha(temp[0])) word.push_back(temp);
                    temp = "";
                    continue;
                }
                temp += tolower(c);
            }
        }
        set<string>st(banned.begin() , banned.end());
        unordered_map<string , int>mpp;
        for(auto c : word){
            if(st.find(c) != st.end())continue;
            mpp[c] ++;
        }
        int maxi = -1;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        for(auto it : mpp){
            if(it.second == maxi)return it.first;
        }
        return " ";
    }
};