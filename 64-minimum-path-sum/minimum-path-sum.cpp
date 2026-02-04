class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int> temp(n,0);
        
        for(int j=0; j<n; j++){
            temp[j] = j==0 ? grid[0][j] : temp[j-1] + grid[0][j];
        }

        for(int i=1; i<m; i++){

            vector<int> dp(n);

            for(int j=0; j<n; j++){
                 
                 if(j==0){
                   dp[j] = grid[i][j] + temp[j];
                 }
                 else{
                    dp[j] = grid[i][j] + min(dp[j-1] , temp[j]);
                 }
                  
            }
            temp = dp;
        }

        return temp[n-1];
    }
};