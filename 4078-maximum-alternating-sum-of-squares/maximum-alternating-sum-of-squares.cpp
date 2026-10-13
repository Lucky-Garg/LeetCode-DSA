class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = abs(nums[i]);
        }
        priority_queue<int>pq;
        for(auto x : nums){
            pq.push(x);
        }
        int n = nums.size();
        int k = 0;
        if(n%2 == 1){
            k = n - (n/2);
        }
        else{
            k = n/2;
        }
        int cnt = 1;
        long long even = 0 , odd = 0;
        while(!pq.empty()){
            long long front = pq.top();
            pq.pop();
            if(cnt <= k){
                even += front*front;
            }
            else{
                odd += front*front;
            }
            cnt++;
        }
        return even - odd;
    }
};