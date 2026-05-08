class Solution {
public:
    
    vector<vector<int>> dir = {
       {-1,0} , {1,0} , {0,-1}, {0,1}
    };

    int solve(int i, int j, int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
        
     
        if(dp[i][j] != -1){
            return dp[i][j];
        }
         
         int cnt = 1;

         for(auto d : dir){
            int x = d[0] + i;
            int y = d[1] + j;

            if(x>=0 && x<m && y>=0 && y<n && mat[i][j] < mat[x][y]){
                 cnt = max(cnt , 1+solve(x,y,m,n,mat,dp));
            }
         }
         return dp[i][j] = cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        int len = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               len = max(len , solve(i,j,m,n,mat,dp));
               //dp[i][j] = len;
            }
        }
        return len;
    }
};