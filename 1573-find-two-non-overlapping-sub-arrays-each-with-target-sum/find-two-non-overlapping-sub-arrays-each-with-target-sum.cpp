class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int result = INT_MAX;
        int bestMin = INT_MAX;
        long long currSum = 0;
        vector<int>bestMinTill(n , INT_MAX);
        while(j < n){
            currSum += arr[j];

            while(currSum > target){
                currSum -= arr[i++];
            }

            if(currSum == target){
                int len = j-i+1;

                if(i > 0 && bestMinTill[i-1] != INT_MAX){
                    result = min(result , len + bestMinTill[i-1]);
                }

                bestMin = min(bestMin , len);
            }

            bestMinTill[j] = bestMin;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};