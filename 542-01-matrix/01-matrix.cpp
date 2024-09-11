class Solution {
public:
    
    int m , n;

    vector<vector<int>> arr{{1,0}, {-1,0}, {0 , 1} , {0 , -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      
      m = mat.size();
      n = mat[0].size();

      vector<vector<int>> ans(m , vector<int>(n , -1));
      queue<pair<int, int>> q;

      for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){

            if(mat[i][j] == 0){
                ans[i][j] = 0;
                q.push({i , j});
            }
        }
      }
  
      while(!q.empty()){
         
         auto it = q.front();
         q.pop();

         int s = it.first;
         int e = it.second;
         
         for(auto &ch : arr){

            int x = s + ch[0];
            int y = e + ch[1];

            if(x >= 0 && y >= 0 && x < m && y < n && ans[x][y] == -1){
                ans[x][y] = 1 + ans[s][e];
                q.push({x , y});
            }
         }
      }
        return ans;
    }
};