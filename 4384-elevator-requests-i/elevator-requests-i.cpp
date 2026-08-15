class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ttl = 0;
        int ele = 0;
        for(int x : requests){
            ttl += abs(ele - x);
            ele = x;
        }
        return ttl;
    }
};