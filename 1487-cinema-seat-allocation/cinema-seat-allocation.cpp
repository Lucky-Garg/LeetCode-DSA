class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , vector<int>>mpp;
        for(auto v : reservedSeats){
            mpp[v[0]].push_back(v[1]);
        }
        int cnt = (n - mpp.size()) * 2;
        for(auto x : mpp){
            auto v = x.second;
            bool grp1 = true , grp2 = true , grp3 = true;
            for(auto e : v){
                if(e >= 2 && e <= 5) grp1 = false;
                if(e >= 4 && e <= 7) grp2 = false;
                if(e >= 6 && e <= 9) grp3 = false;
                
            }
            if(grp1 && grp3)cnt+=2;
            else if(grp1 || grp2 || grp3)cnt+=1;
        }
        return cnt;
    }
};