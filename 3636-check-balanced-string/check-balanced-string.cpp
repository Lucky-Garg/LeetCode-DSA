class Solution {
public:
    bool isBalanced(string num) {
        int odd_sum = 0 , even_sum = 0;
        for(int i = 0 ; i<num.size() ; i++){
            if(i%2){
                odd_sum += num[i]-'0';
            }
            else{
                even_sum += num[i]-'0';
            }
        }
        return even_sum == odd_sum;
    }
};