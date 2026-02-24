class Solution {
public:
    
    
    int solve(int i, int j, int& m, int& n, vector<vector<char>> &mat, vector<vector<int>>& dp){

        if(i >= m || j >= n) return 0;

        if(mat[i][j] == '0') return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i,j+1,m,n,mat,dp);
        int dang  = solve(i+1,j+1,m,n,mat,dp);
        int below = solve(i+1,j,m,n,mat,dp);

        return dp[i][j] = 1 + min({right,dang,below});
    }


    int maximalSquare(vector<vector<char>>& mat) {
         
         int m = mat.size();
         int n = mat[0].size();
         int res = 0;
         vector<vector<int>> dp(m, vector<int>(n,-1));

         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == '1'){
                    int ans = solve(i,j,m,n,mat,dp);
                     res = max(res , ans*ans);
                }
            }
         }
         return res;
    }
};