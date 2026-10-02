class Solution {
public:

    bool check(string &s){
        stack<char>st;
        for(auto c : s){
            if(c == '('){
                st.push(c);
            }
            else{
                if(st.empty())return false;
                else{
                    if(st.top() != '(')return false;
                    else{
                        st.pop();
                    }
                }
            }
        }
        return st.empty();
    }
    void solve(string s , vector<string>&ans , int n){
        if(s.size() == 2*n){
            if(check(s)){
                ans.push_back(s);
            }
            return ;
        }

        s.push_back('(');
        solve(s , ans , n);
        s.pop_back();

        s.push_back(')');
        solve(s , ans , n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve("" , ans , n);
        return ans;
    }
};