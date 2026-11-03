class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int minAns = INT_MAX;
        for(int i = 0 ; i < n ; i+=2){
            string num1 = to_string(nums[i]);
            string num2 = to_string(nums[i+1]);

            string newNum = num1+num2;

            int num = stoi(newNum);
            minAns = min(minAns , num);
        }
        return minAns;
    }
};