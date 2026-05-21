class Solution {
public:
    // int commonLen(int a , int b){
    //     string s1 = to_string(a);
    //     string s2 = to_string(b);
    //     int i = 0 , j = 0;
    //     int cnt = 0;
    //     while(i < s1.size() && j < s2.size()){
    //         if(s1[i] == s2[j])cnt ++;
    //         else{
    //             break;
    //         }
    //         i++ , j++;
    //     }
    //     return cnt;
    // }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // int maxi = -1;
        // for(int x : arr1){
        //     for(int y : arr2){
        //         maxi = max(maxi , commonLen(x , y));
        //     }
        // }
        // return maxi;
        unordered_set<string>st;
        for(auto x : arr1){
            string a = to_string(x);
            string temp= "";
            for(char s : a){
                temp += s;
                st.insert(temp);
            }
        }
        int ans = 0;
        for(auto x : arr2){
            string b = to_string(x);
            string temp = "";
            for(auto s : b){
                temp += s;
                if(st.count(temp)){
                    ans = max(ans , (int)temp.size());
                }
            }
        }
        return ans;
    }
};