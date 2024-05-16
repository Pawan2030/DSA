class Solution {
public:
    
    int row;
    int col;

    void make_row_col_zero(vector<vector<int>>& matrix , int i , int j){

        //--->>NEW LOGIC

        for(int r = 0; r<row; r++){
            matrix[r][j] = 0;
        }

        for(int c = 0; c<col; c++){
            matrix[i][c] = 0;
        }

        return;
    }

    void setZeroes(vector<vector<int>>& matrix){

        row = matrix.size();
        col = matrix[0].size();

        vector<pair<int,int>> vec;

        for(int i=0 ; i<row; i++){

            for(int j=0; j<col; j++){

                 if(matrix[i][j] == 0){
                   vec.push_back({i , j});
                 }
            }
        } 

        for(int i=0; i<vec.size(); i++){

            int r = vec[i].first;
            int c = vec[i].second;

            make_row_col_zero(matrix , r , c);
        }

        return;
    }
};