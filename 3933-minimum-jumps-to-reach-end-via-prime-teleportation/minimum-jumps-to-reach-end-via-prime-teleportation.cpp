class Solution {
public:
    void sieve(int maxEl , vector<bool>&isPrime){
        isPrime[0] = false;
        isPrime[1] = false;

        for(int m = 2 ; m*m <= maxEl ; m++){

            if (isPrime[m]) {
                for (int j = m * m; j <= maxEl; j += m) {
                    isPrime[j] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxEl = 0;
        unordered_map<int , vector<int>>mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]].push_back(i);
            maxEl = max(maxEl , nums[i]);
        }

        vector<bool>visited(n , false);
        vector<bool>isPrime(maxEl+1 , true);
        sieve(maxEl , isPrime);
        queue<int>q;
        q.push(0);

        unordered_set<int>seenPrime;
        int steps = 0;
        while(!q.empty()){
            int sze = q.size();
            while(sze--){

                int idx  = q.front();
                q.pop();

                if(idx == n-1){
                    return steps;
                }

                if(idx-1 >= 0 && !visited[idx-1]){
                    q.push(idx-1);
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]){
                    q.push(idx+1);
                    visited[idx+1] = true;
                }

                if(!isPrime[nums[idx]] || seenPrime.count(nums[idx])){
                    continue;
                }

                for(int multi = nums[idx] ; multi <= maxEl ; multi += nums[idx]){
                    if(!mpp.count(multi))continue;


                    for(int j : mpp[multi]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seenPrime.insert(nums[idx]); 
            }
            steps++;
        }
        return steps;
    }
};