class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n);

        for(int j=0; j<n; j++){
            dp[j] = matrix[0][j];
        }

        for(int i = 1; i<m; i++){
            
            vector<int> curr(n);

            for(int j = 0; j<n; j++){
                
                if(j == 0){
                    curr[j] = matrix[i][j] + min(dp[j] , dp[j+1]);
                }
                else if(j == n-1){
                    curr[j] = matrix[i][j] + min(dp[j] , dp[j-1]);
                }
                else{
                    curr[j] = matrix[i][j] + min({dp[j-1] , dp[j] , dp[j+1]});
                }

            }
            dp = curr;
        }

        return *min_element(begin(dp) , end(dp));
    }
};