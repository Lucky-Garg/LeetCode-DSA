class Solution {
public:
    int countCommas(int n) {
        if(n <= 999)return 0;
        else if(n >= 1000 && n <= 99999)return (n-1000)+1;
        return (99999-1000 )+((n-100000)+1)*2;
    }
};