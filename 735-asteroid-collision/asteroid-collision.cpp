class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x : asteroids){
            bool flag = false;
            if(x > 0){
                st.push(x);
            }
            else{
                while(!st.empty() && st.top()>0){
                    if(st.top() < abs(x)){
                        st.pop();
                    }
                    else if(st.top() == abs(x)){
                        flag = true;
                        st.pop();
                        break;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    st.push(x);
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};