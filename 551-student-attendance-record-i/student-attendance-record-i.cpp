class Solution {
public:
    bool checkRecord(string s) {
        int p = 0 , a = 0  , l = 0 , maxL = -1;
        for(auto c : s){
            if(c =='P')p++;
            if(c == 'A')a++;
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!= 'L'){
                maxL = max(maxL , l);
                l = 0;
            }else{
                l++;
            }
        }
        maxL = max(maxL , l);
        if(a<2 && maxL <3)return true;
        return false; 
    }
};