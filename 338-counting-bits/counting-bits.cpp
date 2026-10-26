class Solution {
public:
    int countSet(int n){
        int cnt = 0;
        while(n){
            if(n & 1 == 1)cnt++;
            n >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i =0 ; i <= n ; i++){
            ans[i] = countSet(i);
        }
        return ans;
    }
};