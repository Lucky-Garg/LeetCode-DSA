class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int n = cheeseSlices;
        if(tomatoSlices == 0 && cheeseSlices == 0)return {0,0};
        else if(tomatoSlices % 2 == 1)return {};
        else{
            // while(cheeseSlices > 0){
            //     if((cheeseSlices*4 +(n - cheeseSlices)*2) == tomatoSlices){
            //         return {cheeseSlices , n-cheeseSlices};
            //     }
            //     cheeseSlices--;
            // }
            for(int i = 0 ; i < n ; i++){
                if((i*4 + (cheeseSlices - i)*2 == tomatoSlices) && i+cheeseSlices-i == n){
                    return {i,cheeseSlices - i};
                }
            }
        }
        return {};
    }
};