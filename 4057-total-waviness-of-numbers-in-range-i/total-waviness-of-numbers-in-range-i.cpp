class Solution {
public:
    int countWaviness(int n){
        string num = to_string(n);
        int cnt = 0;
        for(int i = 1 ; i < num.size()-1 ; i++){
            if((num[i] > num[i-1] && num[i] > num[i+1]) || (num[i] < num[i-1] && num[i]<num[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int wavi = 0;
        for(int i = num1 ; i<= num2 ; i++){
            wavi += countWaviness(i);
        }
        return wavi;
    }
};