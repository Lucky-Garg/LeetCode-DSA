class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int n = cheeseSlices;
        if(tomatoSlices == 0 && cheeseSlices == 0)return {0,0};
        if(tomatoSlices == 2 && cheeseSlices == 1)return {0,1};
        if(cheeseSlices> tomatoSlices)return {};
        else if(tomatoSlices % 2 == 1)return {};
        else{
            while(cheeseSlices > 0){
                if((cheeseSlices*4 +(n - cheeseSlices)*2) == tomatoSlices){
                    return {cheeseSlices , n-cheeseSlices};
                }
                cheeseSlices--;
            }
        }
        return {};
    }
};