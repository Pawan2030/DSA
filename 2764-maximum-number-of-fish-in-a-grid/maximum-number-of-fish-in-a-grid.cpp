class Solution {
public:
    
    int m;
    int n;

    vector<vector<int>> dirt{
        {1,0},{-1,0},{0,1},{0,-1}
    };

    void solve(int i, int j, int &res, vector<vector<int>>& grid, vector<vector<bool>>& visited){

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;

        res += grid[i][j];
        visited[i][j] = true;

        for(auto it : dirt){

            int x = i + it[0];
            int y = j + it[1];
            
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                solve(x, y, res, grid, visited);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {

       m = grid.size();
       n = grid[0].size();
       int ans = 0;

       for(int i=0; i<m; i++){
         for(int j=0; j<n; j++){
             if (grid[i][j] > 0) { // Only process unvisited cells with fish
                    int res = 0;
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    solve(i, j, res, grid,visited);
                    ans = max(ans, res);
                }
         }
       } 
       return ans; 
    }
};