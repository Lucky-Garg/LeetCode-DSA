class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);

        for (auto w : word) {
            hash[w - 'a']++;
        }
        sort(hash.begin(), hash.end(), greater<int>());
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (i <= 7) {
                cnt += hash[i] * 1;
            } else if (i <= 15) {
                cnt += hash[i] * 2;
            } else if (i <= 23) {
                cnt += hash[i] * 3;
            } else {
                cnt += hash[i] * 4;
            }
        }
        return cnt;
    }
};