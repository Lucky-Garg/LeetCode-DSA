class Solution {
public:
    string getHint(string secret, string guess) {
        map<char , vector<int>>mppS , mppG;
        for(int i = 0 ; i < secret.size() ; i++){
            mppS[secret[i]].push_back(i);
            mppG[guess[i]].push_back(i);
        }
        int bull = 0 , cows = 0 ;
        for(auto x : mppG){
            char num = x.first;
            auto v = x.second;
            if(mppS.count(num)){
                if(mppS[num].size() < mppG[num].size()){
                    auto v = mppG[num];
                    set<int>st(v.begin() , v.end());
                    for(int i = 0 ; i < mppS[num].size() ; i++){
                        if(st.count(mppS[num][i])) bull++;
                        else cows++;
                    }
                }
                else{
                    auto v = mppS[num];
                    set<int>st(v.begin() , v.end());
                    for(int i = 0 ; i < mppG[num].size() ; i++){
                        if(st.count(mppG[num][i])) bull++;
                        else cows++;
                    }
                }

               
            }
        }
        string b = to_string(bull);
        string c = to_string(cows);
        string ans = "";
        ans += b ;
        ans += 'A';
        ans += c;
        ans += 'B';
        return ans;
        

    }
};