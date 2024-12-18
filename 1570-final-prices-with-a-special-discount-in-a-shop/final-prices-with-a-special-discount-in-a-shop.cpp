class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> res = prices;

        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
               
               if(prices[i] >= prices[j]){
                  res[i] -= prices[j];
                  break;
               }
            }
        }
        return res;
    }
};