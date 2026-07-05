class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankSet(bank.begin() , bank.end());
        unordered_set<string>vis;

        vis.insert(startGene);

        queue<string>q;
        q.push(startGene);
        
        int lvl = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == endGene) return lvl;

                for(auto c : "ACGT"){
                    for(int i = 0 ; i < curr.size() ; i++){
                        string neigh = curr;
                        neigh[i] = c;

                        if( vis.count(neigh) == 0 && bankSet.count(neigh) ){
                            vis.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};