class Solution {
public:
    bool solve(vector<int>&arr , int i){
        if( i < 0  || i>= arr.size() || arr[i] < 0)
            return false;
        if(arr[i] == 0)
            return true;
        arr[i]*= -1;
        return (solve(arr , i+arr[i]) || solve(arr , i-arr[i]));
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr , start);
    }
};