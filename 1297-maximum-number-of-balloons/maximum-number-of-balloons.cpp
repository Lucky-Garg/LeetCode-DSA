class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int>mppT , mppS;
        for(auto c : text){
            mppT[c]++;
        }
        string s = "balloon";
        for(auto c : s){
            mppS[c]++;
        }
        if(text.size() < s.size())return 0;
        vector<int>ans;
        for(char c : s){
            if(mppS[c] > 0){
                ans.push_back(mppT[c]/mppS[c]);
            }
        }
        int mini = INT_MAX;
        for(auto x : ans){
            mini = min(mini , x);
        }
        return (mini == INT_MAX) ? 0 : mini;
        
    }
};