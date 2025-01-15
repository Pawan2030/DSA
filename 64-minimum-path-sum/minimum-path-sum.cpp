class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        //top down approach
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m , vector<int>(n));

        //lets fill first row
        int sum = 0;
        for(int col = 0; col<n; col++){
            sum += grid[0][col];
            res[0][col] = sum;
        }
        
        sum = 0;
        //lets fill first col
        for(int row = 0; row<m; row++){
            sum += grid[row][0];
            res[row][0] = sum; 
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                res[i][j] = grid[i][j] + min(res[i-1][j] , res[i][j-1]);
                cout<< res[i][j]<<endl;
            }
        }

        return res[m-1][n-1];
    }
};