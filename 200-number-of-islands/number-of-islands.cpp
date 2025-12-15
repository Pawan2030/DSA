class Solution {
public:

   int m , n;

   vector<vector<int>>directions{
      {1 , 0} , {0 , 1} , {0 , -1} , {-1 , 0}
   };

   void solve(int i , int j , vector<vector<char>>& grid){

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }

         grid[i][j] = '0';

         for(auto dir : directions){
             
             int x = i + dir[0];
             int y = j + dir[1];

             solve(x , y , grid);
         }

   }


    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == '1'){
                    solve(i , j , grid);
                    count++;
                }

            }
        }
        return count;
    }
};