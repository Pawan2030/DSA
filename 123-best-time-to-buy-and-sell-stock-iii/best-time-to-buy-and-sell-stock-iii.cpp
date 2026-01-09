class Solution {
public:
    
    int solve(int i, int buy, int trans, vector<int> &prices,  vector<vector<vector<int>>> &dp){
        
        if( i >= prices.size() || trans == 0){
            return 0;
        }

        if(dp[i][buy][trans] != -1){
            return dp[i][buy][trans];
        }
  
        int profit = 0;

        if(buy){
        
            int buyKro     = solve(i+1 , 0 , trans, prices, dp) - prices[i];
            int buySkipKro = solve(i+1 , 1 , trans, prices, dp) - 0;
            profit = max(buyKro , buySkipKro);
        }
        else{
            
            int sellKro     =  solve(i+1 , 1 ,trans-1, prices, dp) + prices[i];
            int sellSkipKro =  solve(i+1 , 0 ,trans, prices, dp) + 0;
            profit = max(sellKro , sellSkipKro);
    
        }
        return dp[i][buy][trans] = profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2 , vector<int>(3,-1)));
        return solve(0 , 1 , 2 , prices, dp);
    }
};