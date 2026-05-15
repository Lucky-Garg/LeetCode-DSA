class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        if( n == 1)return nums[0];
        sort(nums.begin() , nums.end());
        vector<int>neg;
        int neg_cnt = 0;
        long long neg_pro = 1;
        long long pro = 1;
        int cnt_0 = 0;
        for(auto it : nums){
            if(it<0){
                neg_cnt++;
                neg_pro *= it;
                neg.push_back(it);
            }
            else{
                if(it != 0){
                    pro *= it;
                }
                else{
                    cnt_0 ++;
                }
            }
        }
        if(cnt_0 == n)return 0;
        if(neg_cnt == 1 && cnt_0 >0){
            if(neg_cnt +cnt_0 == n)return 0;
        }
        int i = neg_cnt;
        while(neg_cnt % 2 != 0){
            neg_pro /= neg[--i];
            neg_cnt--;
        }
        return pro*neg_pro;
    }
};