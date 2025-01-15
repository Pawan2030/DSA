class Solution {
public:
    
    int n;
    int dp[13][10001];

    int solve(int i, vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        if(i >= n || amount < 0){
            return 1e5;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        //int take = 1e5;
        //if(amount >= coins[i]){
           int take = 1+solve(i, coins, amount-coins[i]);
        
           
        int skip = solve(i+1, coins, amount);

        return dp[i][amount] = min(take , skip);
    }

    int coinChange(vector<int>& coins, int amount) {

       n = coins.size();
       memset(dp , -1, sizeof(dp));
       int ans = solve(0 , coins , amount); 
       return ans == 1e5 ? -1 : ans;
    }
};