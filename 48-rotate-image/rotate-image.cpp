class Solution {
public:

    void rotate(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<(n/2); j++){
                swap(mat[i][j] , mat[i][n-j-1]);
            }
        }
    }
};