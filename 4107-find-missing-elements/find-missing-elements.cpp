class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>hash(101 , -1);
        for(int x : nums){
            hash[x] = 1;
        }
        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());
        vector<int>store;
        for(int i = mini ; i <= maxi ; i++){
            if(hash[i] == -1){
                store.push_back(i);
            }
        }
        return store;
    }
};