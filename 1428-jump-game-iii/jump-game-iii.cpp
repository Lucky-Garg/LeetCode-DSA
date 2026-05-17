class Solution {
public:
    bool solve(vector<int>&arr , int i){
        if( i < 0  || i>= arr.size() || arr[i] < 0)
            return false;
        if(arr[i] == 0)
            return true;
        int jump = arr[i];
        arr[i]*= -1;
        return solve(arr , i + jump) || solve( arr , i - jump);
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr , start);
    }
};