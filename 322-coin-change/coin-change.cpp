class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

       int n = coins.size();

       vector<vector<int>> dp(n+1, vector<int>(amount+1)) ;

       //fill 0th col, we need to make 0 rs so it alredy 0 so we need 0 coins
        for(int i=0; i<=n; i++){
          dp[i][0] = 0;
       }

       //let fill 0th row where we have 0 elements so we cant make that amount it means we need infinite coins to make
       
       for(int i=0; i<=amount; i++){
          dp[0][i] = INT_MAX-1;
       }

       //lest fill the second row -> special case
       for(int val=1; val<=amount; val++){
           
           if(coins[0] != 0 && val%coins[0] == 0){
              dp[1][val] = val/coins[0];
           }
           else{
              dp[1][val] = INT_MAX-1;
           }
        }

        //fill rest dp matrix row - 2 and col - 1
        for(int i=2; i<=n; i++){
            for(int j=1; j<=amount; j++){

                if(j >= coins[i-1]){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};