class Solution {
public:

    void setZeroes(vector<vector<int>>& mat) {
        
        //let keep the info using row and col
        int first_col = 1;
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(mat[i][j] == 0){
                    mat[i][0] = 0; //row num set whice row is zero
                    
                    if(j != 0){
                        mat[0][j] = 0;
                    }
                    else{
                        first_col = 0;
                    }
                }
            }
        }

        //let zero fully 

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){

                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }


        //let check for first row

        if(mat[0][0] == 0){
            for(int i=0; i<n; i++){
                    mat[0][i] = 0;
            }
        }
        
        //for col

        if(first_col == 0){
            for(int i=0; i<m; i++){
                    mat[i][0] = 0;
            }
        }
    }
};