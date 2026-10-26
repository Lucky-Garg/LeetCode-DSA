class Solution {
public:
    int minBitFlips(int start, int goal) {
        // 10 : 1010
        // 7  : 0111
        int flipCnt = 0;
        while(start != goal){
            int strtRightBit = (start & 1);
            int goalRightBit = (goal & 1);

            if(strtRightBit != goalRightBit)flipCnt++;

            start >>= 1;
            goal >>= 1;
        }
        return flipCnt;
    }
};