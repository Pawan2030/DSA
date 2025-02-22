class Solution {
public:
    
    int m , n;

    vector<vector<int>> directions{
        {0 ,1} , {0,-1} , {1 , 0} , {-1 , 0}
    };

    void coverIsaland(int i, int j, vector<vector<char>>& grid){
        
        if(i < 0 || i >= m || j < 0 || j>=n || grid[i][j] == '0') return;

        grid[i][j] = '0';

        for(vector<int>& dir : directions){

            int x = i + dir[0];
            int y = j + dir[1];
            
            //if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'){
                coverIsaland(x , y , grid);
           // }
        }

    }


    int numIslands(vector<vector<char>>& grid) {
        
         m = grid.size();
         n = grid[0].size();

        int num = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                   num++;
                   coverIsaland(i,j,grid);
                }
            }
        }
        return num;
    }
};