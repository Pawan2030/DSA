class Solution {
public:
    
    int rows;
    int cols;

    bool isMagicalGrid(vector<vector<int>>& mat , int x , int y){
        
        //distinct and 1 to 9

        unordered_set<int> st;

        for(int i=0; i<3; i++){

            for(int j=0; j<3; j++){

                if(mat[x+i][y+j] <= 0 || mat[x+i][y+j] > 9 || st.count(mat[x+i][y+j])){
                    return false;
                }
                st.insert(mat[x+i][y+j]);
            }
        }

        //row and col for grid 3*3

        int equal = mat[x][y] + mat[x][y+1] + mat[x][y+2];

          for(int i=0; i<3; i++){
             
             if(equal != mat[x+i][y] + mat[x+i][y+1] + mat[x+i][y+2]){
                return false;
             }

             if(equal != mat[x][y+i] + mat[x+1][y+i] + mat[x+2][y+i]){
                return false;
             }
         }

         //daigonal

         if(equal != mat[x][y] + mat[x+1][y+1] + mat[x+2][y+2]){
            return false;
         }

         if(equal != mat[x][y+2] + mat[x+1][y+1] + mat[x+2][y]){
            return false;
         }

         return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

       rows = grid.size();
       cols = grid[0].size();

       int magic = 0;

       for(int i=0; i<=rows-3; i++){
          
          for(int j=0; j<=cols-3; j++){
             
              if(isMagicalGrid(grid , i , j)){
                magic++;
              }
          }
       } 
       return magic;
    }
};