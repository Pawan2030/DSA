class Solution {
public:


    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int row = rowSum.size();
        int col = colSum.size();

        vector<vector<int>> mat(row , vector<int>(col , 0));

        for(int i = 0; i<row; i++){

            for(int j = 0; j<col; j++){

                int val = min(rowSum[i] , colSum[j]);

                mat[i][j] = val;

                rowSum[i] -= val;
                colSum[j] -= val;

                if( rowSum[i] <= 0) rowSum[i] = 0;
                if( colSum[j] <= 0) colSum[j] = 0;
            }
        }
        return mat;
    }
};