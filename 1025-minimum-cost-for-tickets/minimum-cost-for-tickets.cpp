class Solution {
public:
    
    int n;

    int solve(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp){

        //base case
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        //one day pass
        int oneDayPass    = costs[0] + solve(idx+1, days, costs, dp);

        int maxDay = days[idx] + 7;
        int j = idx;

        while(j < n && days[j] < maxDay){
            j++;
        }

        //7 days pass
        int sevenDayPass  = costs[1] + solve(j, days, costs, dp);

        maxDay = days[idx] + 30;
        j = idx;

        while(j < n && days[j] < maxDay){
            j++;
        }

        //30 days pass
        int thirtyDayPass = costs[2] + solve(j, days, costs, dp);

        return dp[idx] = min({oneDayPass, sevenDayPass, thirtyDayPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n+1, -1);
        return solve(0,days,costs,dp);
    }
};