class Solution {
public:
    int m;
    int n;

    int row;
    int col;

    void fill(vector<string>& grid , vector<vector<int>>& mat , int row , int col){
        
        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){
                 
                char ch = grid[i][j];

                if(ch == ' '){
                  continue;
                }
                else if(ch == '\\'){

                    mat[i*3][j*3]     = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
                else{ 
                    mat[i*3][j*3+2]    = 1;
                    mat[i*3+1][j*3+1]  = 1;
                    mat[i*3+2][j*3]    = 1;
                }
            }
        }
    }

    void dfs(vector<vector<int>> &mat , int x , int y){
         
         //return condition
         if(x<0 || x >= row || y<0 || y >= col || mat[x][y] == 1){
            return;
         }

         mat[x][y] = 1;
        
         dfs(mat , x , y+1);
         dfs(mat , x+1 , y);
         dfs(mat , x , y-1);
         dfs(mat , x-1, y);

    }

    int regionsBySlashes(vector<string>& grid) {

       m = grid.size();
       n = grid[0].size();

       row = m*3;
       col = n*3;

       int region = 0;


       vector<vector<int>> mat(row , vector<int>(col , 0));

       fill(grid , mat , row , col);

       for(int i=0; i<row; i++){ 
         for(int j=0; j<col; j++){

            if(mat[i][j] == 0){
                region++;
                dfs(mat , i , j);
            }
         }
       }
       return region;
    }
};