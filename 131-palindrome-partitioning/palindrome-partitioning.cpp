class Solution {
public:
    bool isPalin(string&s){
        int l = 0 , r = s.size()-1;
        while(l<r){
            if(s[l] != s[r])return false;
            l++,r--;
        }
        return true;
    }
    void getAllPart(string s ,vector<string>&part ,vector<vector<string>>&ans){
        if(s == ""){
            ans.push_back(part);
            return ;
        }
        for(int i = 0 ; i<s.size() ; i++){
            string sub = s.substr(0,i+1);
            if(isPalin(sub)){
                part.push_back(sub);
                getAllPart(s.substr(i+1) , part , ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;
        getAllPart(s , part , ans);
        return ans;
    }
};