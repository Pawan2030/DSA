class Solution {
public:
    
    int m , n;
    
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& grid){

        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(i == m-1){ // last row so only can go RIGHT--->>
            return dp[i][j] = grid[i][j] + solve(i,j+1,grid);
        } 
        else if(j == n-1){ // last col so only can go DOWN--->>
            return dp[i][j] = grid[i][j] + solve(i+1,j,grid);
        } 
        else{
            return dp[i][j] = grid[i][j] + min(solve(i+1,j,grid) , solve(i,j+1,grid));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
       
       m = grid.size();  // row
       n = grid[0].size();  //col
       memset(dp,-1,sizeof(dp));
       return solve(0 , 0 , grid);

    }
};