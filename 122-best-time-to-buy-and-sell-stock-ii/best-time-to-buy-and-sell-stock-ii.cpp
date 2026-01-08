class Solution {
public:
    
    int t[30001][2];

    int solve(int i, int buy, vector<int> &prices){

        if( i>= prices.size()){
            return 0;
        }

        if(t[i][buy] != -1){
            return t[i][buy];
        }
        
        int profit = 0;

        if(buy){

            int buyKro     = solve(i+1 , 0 , prices) - prices[i];
            int buySkipKro = solve(i+1 , 1 , prices) - 0;
            profit = max(buyKro , buySkipKro);
        }
        else{

            int sellKro     =  solve(i+1 , 1 , prices) + prices[i];
            int sellSkipKro =  solve(i+1 , 0 , prices) + 0;
            profit = max(sellKro , sellSkipKro);
        }

        return t[i][buy] = profit;
    }


    int maxProfit(vector<int>& prices) {
        memset(t , -1, sizeof(t));
        return solve(0 , 1 , prices);
    }
};