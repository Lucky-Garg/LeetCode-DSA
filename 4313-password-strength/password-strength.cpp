class Solution {
public:
    int passwordStrength(string password) {
        set<char>s(password.begin() , password.end());
        int strength = 0;
        for(auto c : s){
            if(isalpha(c)){
                if(isupper(c)){
                    strength += 2;
                }
                else{
                    strength += 1;
                }
            }
            else if(isdigit(c)){
                strength += 3;
            }
            else{
                strength +=5;
            }
        }
        return strength;
    }
};