class Solution {
public:

    bool check_for_col(vector<vector<int>>& matrix , int c , int& min_val){

        for(int i = 0 ; i < matrix.size() ; i++){

            int val = matrix[i][c];

            if(val > min_val){
                return false;
            }
        }

        return true;

    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> arr;

        for(int i=0; i<row; i++){

            int min_val = INT_MAX;
            int c;

            for(int j=0; j<col; j++){
               
               if(min_val > matrix[i][j]){
                  min_val = matrix[i][j];
                  c = j;
               }
                
            }

            if(check_for_col(matrix , c , min_val) == true){
                arr.push_back(min_val);
            }
        }

        return arr;
    }
};