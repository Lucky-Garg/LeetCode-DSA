class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        // int i = 0 , j = ans.size()-1;
        // while(i <= j){
        //     swap(ans[i] , ans[j]);
        //     i++ , j--;
        // }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};