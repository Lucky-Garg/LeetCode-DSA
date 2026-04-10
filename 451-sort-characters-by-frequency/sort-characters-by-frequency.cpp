class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        priority_queue<pair<int , char>>pq;
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }
        string ans =  "";
        while(!pq.empty()){
            auto x  = pq.top();
            pq.pop();
            while(x.first>0){
                ans+=x.second;
                x.first--;
            }
        }
        return ans;
    }
};