class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i = 0 ; i < m ; i++){
            string temp = "";
            temp.push_back('.');
            for(int j = 0 ; j< n-1 ; j++){
                if(i == m-1){
                    temp.push_back('.');
                }
                else{
                    temp.push_back('#');
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};