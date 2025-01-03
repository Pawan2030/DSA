class Solution {
public:
    int f(int ind,vector<int> &costs,vector<int> &days,int n,vector<int> &dp){

        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int Day1=costs[0]+f(ind+1,costs,days,n,dp);
        int i;
        for(i=ind;i<n;i++){
            if(days[i]>=days[ind]+7){
                break;
            }
        }
        int Day7=costs[1]+f(i,costs,days,n,dp);
        int j;
        for(j=ind;j<n;j++){
            if(days[j]>=days[ind]+30){
                break;
            }
        }
        int Day30=costs[2]+f(j,costs,days,n,dp);

        
        return dp[ind]=min(Day1,min(Day7,Day30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        int n=days.size();
        vector<int> dp(n+1,-1);
        return f(0,costs,days,n,dp);
        
    }
};