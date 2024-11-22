class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

       int m = matrix.size();
       int n = matrix[0].size();
       int maxSameRow = 0;

       for(int i=0; i<m; i++){
          
          vector<int> temp(n);
          temp = matrix[i];

          vector<int> flip(n);

          for(int k=0; k<n; k++){
             if(temp[k] == 0){
                flip[k] = 1;
             }
             else{
                flip[k] = 0;
             }
          }
          
          int cnt = 1;

          for(int j= i+1 ; j<m; j++){
             
             if(temp == matrix[j] || flip == matrix[j]){
                cnt++;
             }
          }

          maxSameRow = max(maxSameRow , cnt);
       } 
       return maxSameRow;
    }
};