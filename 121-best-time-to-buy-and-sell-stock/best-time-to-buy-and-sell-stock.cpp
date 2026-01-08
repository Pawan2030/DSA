class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = INT_MIN;
        int buy = prices[0];

        for(int i=1; i<n; i++){

            buy = min(buy , prices[i-1]);
            profit = max(profit , prices[i] - buy);
        }

        return profit < 0 ? 0 : profit;
    }
};