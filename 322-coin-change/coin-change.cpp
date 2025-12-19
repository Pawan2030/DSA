class Solution {
public:
    
    int t[13][10001];

    int solve(int i , int n , vector<int>& coins , int amount){

        if(amount == 0){
           return 0;
        }

        if(i >= n || amount < 0) return 10e5;

        if(t[i][amount] != -1) return t[i][amount];
         
        int take = 10e5;

        if(coins[i] <= amount){
            take = 1 + solve(i , n , coins , amount-coins[i]);
        }

        int skip = solve(i+1 , n , coins , amount);

        return t[i][amount] = min(take , skip);

    }
 
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        //int ans = INT_MAX;
        memset(t , -1 , sizeof(t));

        int ans = solve(0 , n , coins , amount);

        if(ans == 10e5) return -1;

        return ans;
    }
};