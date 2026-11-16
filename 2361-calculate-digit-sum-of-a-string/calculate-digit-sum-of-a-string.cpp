class Solution {
public:
    string sumDig(string s){
        int sum = 0;
        for(auto c : s){
            sum += (c-'0');
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        while(s.size() > k){
            string sum = "";
            for(int i = 0 ; i < s.size() ; i+=k){
                string temp = s.substr(i , k);
                cout << temp << " ";
                sum += sumDig(temp);
                cout << " " << sum << " ";
            }
            s = sum;
        }
        return s;
    }
};