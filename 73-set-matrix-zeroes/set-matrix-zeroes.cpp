class Solution {
public:
    int row;
    int col;

    void setZeroes(vector<vector<int>>& matrix) {

        row = matrix.size();
        col = matrix[0].size();

        vector<int> row_zero(row , 0);
        vector<int> col_zero(col , 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (matrix[i][j] == 0) {
                    row_zero[i] = 1;
                    col_zero[j] = 1;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                 
                 if(row_zero[i] == 1 || col_zero[j] == 1){
                    matrix[i][j] = 0;
                 }
            }
        }
    }
};