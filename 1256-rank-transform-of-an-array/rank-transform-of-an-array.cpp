class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>s(arr.begin() , arr.end());
        vector<int>temp ;
        for(auto x : s){
            temp.push_back(x);
        }
        sort(temp.begin() , temp.end());
        unordered_map<int ,int>mpp;
        for(int i = 0  ; i < temp.size() ; i++){
            mpp[temp[i]] = i+1;
        }
        vector<int>ans;
        for(auto x : arr){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};