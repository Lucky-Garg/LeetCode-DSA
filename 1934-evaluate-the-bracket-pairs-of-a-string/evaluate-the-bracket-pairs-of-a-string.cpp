class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string>mpp;
        for(auto vec : knowledge){
            mpp[vec[0]] = vec[1];
        }

        string ans =  "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                string temp = "";
                int j = i+1;
                while(j < s.size() && s[j] != ')'){
                    if(s[j]!=')')temp += s[j];
                    j++;
                }
                if(mpp.count(temp)){
                    ans += mpp[temp];
                }
                else{
                    ans += '?';
                }
                i = j+1;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans ;
    }
};