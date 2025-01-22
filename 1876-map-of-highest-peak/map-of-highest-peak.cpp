class Solution {
public:
    
     vector<vector<int>> directions{
        {0,1},{0,-1},{1,0},{-1,0}
    };

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         
         int m = isWater.size();
         int n = isWater[0].size();

         vector<vector<int>> mat(m,vector<int>(n,-1));
         queue<pair<int,int>> q;
         
         //fill all water(1) with height = 0
         for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(isWater[i][j] == 1){
                    mat[i][j] = 0;
                    q.push({i,j});
                }
            }
         }

         while(!q.empty()){

            auto it = q.front();
            q.pop();
            
            int x = it.first;
            int y = it.second;

            for(auto dir : directions){

                int i = dir[0];
                int j = dir[1];

                int new_x = x+i;
                int new_y = y+j;

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && mat[new_x][new_y] == -1){
                    mat[new_x][new_y] = mat[x][y]+1;
                    q.push({new_x,new_y});
                }

            }



         }


         return mat;
    }
};