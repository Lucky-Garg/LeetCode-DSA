class Solution {
public:
    void pushDigit(vector<int>&ans , int n){
        string num = to_string(n);
        for(auto c : num){
            int I = c - '0';
            ans.push_back(I);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it : nums){
            pushDigit(ans , it);
        }
        return ans;
    }
};