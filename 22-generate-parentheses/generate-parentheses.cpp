class Solution {
public:
    bool check(string & s){
        stack<char>st;
        for(auto c : s){
            if(!st.empty() && st.top() == '(' && c ==')')st.pop();
            else st.push(c);
        }
        return st.empty();
    }
    void find(string s , vector<string>& ans , int n){
        if(s.size() == 2*n){
            if(check(s))ans.push_back(s);
            return;
        }
        s.push_back('(');
        find(s , ans , n);
        s.pop_back();
        s.push_back(')');
        find(s , ans , n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        find("" , ans , n);
        return ans;
    }
};