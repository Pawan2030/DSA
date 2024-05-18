class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();


        //check Zero avaible or not

        int col_zero = 1;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(matrix[i][j] == 0){

                    //for row
                    matrix[i][0] = 0;

                    //for col
                    if( j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col_zero = 0;
                    }
                }
            }
        }

        //phase second-> set zero where zero avaible

        for(int i=1; i<m; i++){

            for(int j=1; j<n; j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //now let talk about first row

        if(matrix[0][0] == 0){

            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        } 

        if(col_zero == 0){

            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        } 
    }
};