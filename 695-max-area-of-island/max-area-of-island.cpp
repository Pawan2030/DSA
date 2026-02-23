class Solution {
public:

   vector<vector<int>> directions{
     {0,1}, {0,-1}, {1,0}, {-1,0}
   };

   void solve(int &r, int &c, int &m, int &n, vector<vector<int>> &grid, int &cnt){
        
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c] == 0){
            return;
        }

        cnt += 1;
        grid[r][c] = 0;

        for(auto &dir : directions){

            int newRow = r + dir[0];
            int newCol = c + dir[1];
            solve(newRow, newCol, m, n, grid, cnt);
        }
   }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
         
         int m = grid.size();
         int n = grid[0].size();
         int res = 0;

         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    solve(i,j,m,n,grid,cnt);
                    res = max(res , cnt);
                }
            }
         }
         return res;
    }
};