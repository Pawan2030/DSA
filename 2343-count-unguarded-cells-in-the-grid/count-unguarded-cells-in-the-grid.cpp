class Solution {
public:

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> mat(m , vector<int>(n , 0));
        //0 -> ungurd
        //1 -> gurd
        //2 -> wall
        //3  -> mark gurd

       for (auto& wall : walls) {
            mat[wall[0]][wall[1]] = 2;
        }

        for (auto& guard : guards) {
            mat[guard[0]][guard[1]] = 1;
        }

        for(auto it : guards){
            int r = it[0];
            int c = it[1];

            //up fix -> row-1 , col
            for(int i=r-1; i>=0; i--){
                if(mat[i][c] == 2 || mat[i][c] == 1) break;
                mat[i][c] = 3;
            }

            //down fix -> row+1 , col
            for(int i=r+1; i<m; i++){
                if(mat[i][c] == 2 || mat[i][c] == 1) break;
                mat[i][c] = 3;
            }

            //left fix -> row , col-1
            for(int j=c-1; j>=0; j--){
                if(mat[r][j] == 2 || mat[r][j] == 1) break;
                mat[r][j] = 3;
            }

            //right fix -> row , col+1
            for(int j=c+1; j<n; j++){
                if(mat[r][j] == 2 || mat[r][j] == 1) break;
                mat[r][j] = 3;
            }
        }

        int unguard = 0;

        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                   unguard++;
                }
            }
        }
        return unguard;
    }
};