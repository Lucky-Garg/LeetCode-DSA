class Solution {
public:
    int cntDiff(string s , string p){
        if(s == p)return 0;
        int cnt = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]  != p[i])cnt++;
        }
        return cnt;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // unordered_map<string , bool>mpp;
        // for(auto it : queries){
        //     mpp[it] = false;
        // }  
        vector<string>ans;
        for(auto it : queries){
            for(auto s : dictionary){
                if(cntDiff(it , s) <=2){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};