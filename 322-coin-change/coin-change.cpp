class Solution {
public:
    
    int n;

    int dp[13][10001];

    int solve(int i , int amount , vector<int>& coins){

        if(amount == 0){
            return 0;
        }

        if(i >= n || amount < 0) return 1e5;

        if(dp[i][amount] != -1) return dp[i][amount];
        
        int take = INT_MAX;
        if(amount >= coins[i]){
           take = 1+solve(i , amount-coins[i] , coins);
        }

        int skip = solve(i+1 , amount, coins);

        return dp[i][amount] = min(take , skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        n = coins.size();
        memset(dp , -1 , sizeof(dp));
        
       int ans = solve(0 , amount , coins);

       return ans == 1e5 ? -1 : ans;
    }
};