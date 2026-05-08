class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp = score;
        sort(temp.begin() , temp.end() , greater<int>());
        unordered_map<int,int>mpp;
        for(int i = 0 ; i <temp.size() ; i++){
            mpp[temp[i]] = i+1;
        }
        vector<string>ans;
        for(int i = 0 ; i < score.size() ; i++){
            if(mpp[score[i]] == 1){
                ans.push_back("Gold Medal");
            }
            else if(mpp[score[i]] == 2){
                ans.push_back("Silver Medal");
            }
            else if(mpp[score[i]] == 3){
                ans.push_back("Bronze Medal");
            }
            else{
                string s = to_string(mpp[score[i]]);
                ans.push_back(s);
            }
        }
        return ans;
    }
};