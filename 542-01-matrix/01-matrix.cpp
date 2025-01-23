class Solution {
public:

     vector<vector<int>> directions{
       {0,1},{0,-1},{1,0},{-1,0}
     };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        //it kind of multi-source BFS
        int m = mat.size();
        int n = mat[0].size();

         vector<vector<int>> res(m , vector<int>(n,-1));
         queue<pair<int,int>> q;

         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
         }

         while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto dir : directions){

                int x = dir[0] + i;
                int y = dir[1] + j;

                if(x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1){
                    res[x][y] = res[i][j]+1;
                    q.push({x,y});
                }
            }

         }
         return res;
    }
};