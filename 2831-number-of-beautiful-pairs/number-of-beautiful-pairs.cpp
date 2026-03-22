class Solution {
public:
    int fd(int n) {
        while (n >= 10) {
            n = n / 10;
        }
        return n;
    }
    int ld(int n) { return n % 10; }
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (gcd(fd(nums[i]), ld(nums[j])) == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};