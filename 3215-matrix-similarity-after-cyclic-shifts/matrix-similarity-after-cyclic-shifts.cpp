class Solution {
public:
    void leftRotate(vector<int>&arr){
        int temp = arr[0];
        for(int i = 0 ; i<arr.size()-1 ;i++){
            arr[i] = arr[i+1];
        }
        arr[arr.size()-1]=temp;
    }
    void rightRotate(vector<int>&arr){
        int temp = arr[arr.size()-1];
        for(int i = arr.size()-1 ; i>0 ; i--){
            arr[i] = arr[i-1];
        }
        arr[0]=temp;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>temp = mat;
        for(int i = 0 ; i<k ; i++){
            for(int  i = 0 ; i<mat.size(); i++){
                if(i%2 ==0){
                    leftRotate(mat[i]);
                }
                else{
                    rightRotate(mat[i]);
                }
            }
        }
        
        return temp == mat;
    }
};