class Solution {
public:
    int maxDistance(string moves) {
        int vertD = 0;
        int horiD = 0;
        int cntdash = 0;
        for(auto c : moves){
            if(c == '_'){
                cntdash ++;
            }
            else if(c == 'L'){
                horiD --;
            }
            else if( c == 'D'){
                vertD--;
            }
            else if(c == 'U'){
                vertD ++;
            }
            else {
                horiD ++;
            }
        }
        return abs(vertD)+abs(horiD)+cntdash;
    }
};