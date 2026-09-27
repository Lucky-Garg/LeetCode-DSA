class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ')'){
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty())st.pop();
                for(auto c : temp){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};