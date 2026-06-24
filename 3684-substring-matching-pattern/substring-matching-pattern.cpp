class Solution {
public:
    bool hasMatch(string s, string p) {
        string prevSub ;
        string nextSub ;
        for(int i = 0 ; i < p.size() ; i++){
            if(p[i] == '*'){
                prevSub = p.substr(0,i);
                nextSub = p.substr(i+1);
            }
        }
        if(s.find(prevSub) != string ::npos){
            auto it=s.find(prevSub);
            s.erase(0,it+prevSub.length());
            auto it2=s.find(nextSub);
            if(it2!=string::npos) return true;
        }
        return false;
    }
};