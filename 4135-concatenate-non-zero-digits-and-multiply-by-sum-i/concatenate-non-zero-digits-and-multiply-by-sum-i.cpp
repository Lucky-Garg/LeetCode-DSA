class Solution {
public:
    long long digitComput(int n){
        string num = to_string(n);
        string newNum = "";
        long long sum = 0;
        for(auto c : num){
            if(c != '0'){
                newNum+=c;
                sum += c-'0';
            }
        }
        long long number;
        if(newNum == ""){
            return 0;
        }else{
            number = stoi(newNum);
        }
        return number*sum;
    }
    long long sumAndMultiply(int n) {
        return digitComput(n);
    }
};