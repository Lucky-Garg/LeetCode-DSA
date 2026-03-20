class Solution {
public:
    int word_count(string &s){
        int cnt = 0;
        for(auto ch : s){
            if(isspace(ch))cnt++;
        }
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int, greater<string>> mpp;
        for(int i = 0 ; i<messages.size();i++){
            mpp[senders[i]] += word_count(messages[i]);
        }
        int maxi = -1;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        for(auto x : mpp){
            if(x.second == maxi){
                return x.first;
            }
        }
        return " ";
    }
};