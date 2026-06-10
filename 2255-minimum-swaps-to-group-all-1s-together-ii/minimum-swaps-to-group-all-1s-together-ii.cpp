class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int windowSize = 0;
        for(int x  : arr){
            if(x == 1){
                windowSize++;
            }
        }
        if(windowSize <=1 )return 0;
        int l = 0  , r = 0 ;
        
        int ans = INT_MAX;

        int cnt0 = 0;
        while(r < n + windowSize -1){
            if(r-l+1 <windowSize){
                if(arr[r%n] == 0)cnt0 ++;
                r++;
            }
            else if( r-l+1 == windowSize){
                if(arr[r%n] == 0)cnt0++;
                ans = min(ans , cnt0);
                r++;
            }
            else{
                if(arr[l%n] == 0){
                    cnt0--;
                }
                if(arr[r%n] == 0){
                    cnt0++;
                }
                ans = min(ans , cnt0);
                l++,r++;
            }
        }
        return ans;
    }
};