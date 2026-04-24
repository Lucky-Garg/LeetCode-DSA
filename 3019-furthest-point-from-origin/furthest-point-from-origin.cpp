class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0, cntR = 0 , cntD = 0;
        for(auto c : moves){
            if( c == 'L')cntL++;
            if( c == 'R')cntR++;
            if( c == '_')cntD++;
        }
        if(cntL == cntR || cntL > cntR){
            return ((cntL+cntD) - cntR);
        }
        else {
            return ((cntR + cntD) - cntL);
        }
        return -1;
    }
};