class Solution {
public:
    bool check(long long  n , int x){
        if(n%10 != x)return false;
        while(n>=10){
            n/=10;
        }
        return (n==x);
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            long long sum = 0;
            for(int j = i; j < nums.size() ; j++){
                sum += nums[j];
                if(check(sum , x))cnt++;
            }
        }
        return cnt;
    }
};