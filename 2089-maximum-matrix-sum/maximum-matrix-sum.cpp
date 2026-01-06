class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long minus = 0;
        int miniEle = INT_MAX;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0){
                    minus++;
                }

                miniEle = min(miniEle , abs(matrix[i][j]));
            }
        }

        if(minus%2 == 0){
            return sum;
        }

        return sum - 2*miniEle;
    }
};