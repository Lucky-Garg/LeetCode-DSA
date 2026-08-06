class Solution {
public:
    int digitPro(int n){
        int pro = 1;
        while(n ){
            int d = n%10;
            pro *= d;
            n /= 10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        for(int i = n ; i <= 100 ; i++){
            if(digitPro(i)%t == 0){
                return i;
            }
        }
        return -1;
    }
};