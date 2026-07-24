class Solution {
public:
    string reverseWords(string s) {
        int strt = 0;
        while(isspace(s[strt])){
            strt++;
        }
        int end = s.size()-1;
        while(isspace(s[end])){
            end--;
        }
        stack<string>st;
        string temp = "";
        int spce_cnt = 0;
        for(int i = strt ; i <= end ; i++){
            if(!isspace(s[i])){
                temp += s[i];
            }
            else{
                spce_cnt++;
                if(spce_cnt == 1){
                    if(temp != "")st.push(temp);
                    spce_cnt = 0; 
                    temp = "";
                }
            }
        }
        st.push(temp);
        string ans = "";
        while(!st.empty()){
            string t = st.top();
            st.pop();
            ans += t + " ";
        }
        ans.pop_back();
        return ans;
    }
};