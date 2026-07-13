class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        vector<int>ans;
        for(int i = 2 ; i <= 9 ; i++){
            for(int j = 0 ; j+i <= 9 ; j++){
                int n = stoi(num.substr(j , i));
                if(n >= low && n <= high){
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
};