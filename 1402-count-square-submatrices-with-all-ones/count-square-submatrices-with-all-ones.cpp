class Solution {
public:
	  int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(),  ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 and j>0 and matrix[i][j]>0)
                    matrix[i][j] = 1+min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};