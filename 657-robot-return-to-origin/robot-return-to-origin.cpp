class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0 , j = 0;
        for(auto c : moves){
            if(c == 'U'){
                i=i-1;
            }
            else if(c == 'D'){
                i = i+1;
            }
            else if(c == 'L'){
                j = j+1;
            }
            else{
                j = j-1;
            }
        }
        return (i == 0 && j == 0);
    }
};