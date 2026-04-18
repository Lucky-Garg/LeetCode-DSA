class Solution {
public:
    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int num = stoi(s);
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};