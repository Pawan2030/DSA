class Solution {
public:
    int n;
    int t[13][10001];

    int solve(int i, vector<int>& coins, int sum){

        if(sum == 0){
            return 0;
        }

        if(i >= n || sum < 0){
            return 1e7;
        }

        if(t[i][sum] != -1){
           return t[i][sum];
        }

        int take = 1 + solve(i, coins, sum-coins[i]);
        int skip =     solve(i+1 , coins , sum);

        return t[i][sum] = min(take,skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0){
            return 0;
        }
        n = coins.size();
        memset(t, -1, sizeof(t));
        int ans = solve(0, coins, amount);
        return ans == 1e7 ? -1 : ans;
    }
};