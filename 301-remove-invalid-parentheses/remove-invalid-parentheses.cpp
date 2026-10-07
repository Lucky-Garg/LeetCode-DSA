class Solution {
public:
    int maxLen;
    void solve(string&s , int idx , int openCnt , string&curr , unordered_set<string>&st){
        if(openCnt < 0)return ;

        if(idx == s.size()){
            if(openCnt == 0){
                if(curr.size() > maxLen){
                    maxLen = curr.size();
                    st.clear();
                }
                if(curr.size() == maxLen){
                    st.insert(curr);
                }
            }
            return ;
        }

        if(s[idx] != '(' && s[idx] != ')'){
            curr.push_back(s[idx]);
            solve(s , idx+1 , openCnt , curr , st);
            curr.pop_back();
            return ;
        }

        curr.push_back(s[idx]);
        solve(s , idx+1 , openCnt +(s[idx] == ')' ? -1 : 1) , curr , st);
        curr.pop_back();

        solve(s , idx+1 , openCnt , curr , st);
    }
    vector<string> removeInvalidParentheses(string s) {
        maxLen = 0;
        unordered_set<string>st;
        string curr = "";
        solve(s , 0 , 0 , curr , st);
        for(auto x : st){

            cout << x << " ";
        }
        vector<string>ans(st.begin() , st.end());
        return ans;

    }
};