class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> dp(n);

        for(int i=0; i<n; i++){
            dp[i] = mat[0][i];
        }


        for(int i=1; i<m; i++){

            vector<int> curr(n);

            for(int j=0; j<n; j++){

                if(j == 0){
                    curr[j] = mat[i][j] + min(dp[j] , dp[j+1]);
                }
                else if(j == n-1){
                    curr[j] = mat[i][j] + min(dp[j] , dp[j-1]);
                }
                else{
                    curr[j] = mat[i][j] + min({dp[j] , dp[j-1] , dp[j+1]});
                }
            }

            dp = curr;

        }

        return *min_element(dp.begin() , dp.end());
    }
};