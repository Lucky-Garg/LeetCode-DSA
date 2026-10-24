class Solution {
public:
    int solve(string date , vector<int>days){
        int month = stoi(date.substr(0 , 2));
        int totalDays = stoi(date.substr(3 , 2));
        for(int i = 0 ; i < month-1 ; i++){
            totalDays += days[i];
        }
        return totalDays;


    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
        int aliceArr = solve(arriveAlice , days);
        int aliceLeave = solve(leaveAlice , days);
        int bobArr = solve(arriveBob , days);
        int bobLeave = solve(leaveBob , days);

        return max(0, min(aliceLeave, bobLeave) -
                          max(aliceArr, bobArr) + 1);
    }
};