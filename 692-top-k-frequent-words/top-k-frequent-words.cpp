class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string , int >mpp;
        for(auto s : words){
            mpp[s]++;
        }
        priority_queue<pair<int , string> ,vector<pair<int,string>> , cmp>pq;
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }
        while(!pq.empty()&& k>0){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
            k--;
        }
        return ans;
    }
};