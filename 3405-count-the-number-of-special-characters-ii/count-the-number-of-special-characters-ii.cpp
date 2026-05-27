class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, pair<int, int>> mpp;
        for (int i = 0; i < word.size(); i++) {
            mpp[word[i]].first++;
            if (islower(word[i])) {
                mpp[word[i]].second = i;
            } else if (isupper(word[i]) && mpp[word[i]].first == 1) {
                mpp[word[i]].second = i;
            }
        }
        int cnt = 0;
        for (auto c : word) {
            if (islower(c)) {
                if (mpp[toupper(c)].first > 0) {
                    int lowerIdx = mpp[c].second;
                    int upperIdx = mpp[toupper(c)].second;
                    if (lowerIdx < upperIdx) {
                        cnt++;
                    }
                    mpp.erase(c);
                    mpp.erase(toupper(c));
                }
            }
        }
        return cnt;
    }
};