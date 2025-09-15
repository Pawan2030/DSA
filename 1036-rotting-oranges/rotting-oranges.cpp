class Solution {
public:
    
    vector<vector<int>> directions = {
      {0,1}, {0, -1}, {1 , 0}, {-1,0}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        //put all the rotten Oragen in the Queue

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }
        
        int mint = 0;

        while(!q.empty()){
            
            int size = q.size();
            bool Rotate = false;
            for(int k=0; k<size; k++){
                 auto pair = q.front();
                 q.pop();

                 for(auto dir : directions){
                      
                      int newRow = pair.first  + dir[0];
                      int newCol = pair.second + dir[1];

                      if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                           q.push({newRow , newCol});
                           grid[newRow][newCol] = 2;
                           Rotate = true;
                      }
                 }
            }

            if(Rotate == true)
             mint++;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                   return -1;
                }
            }
        }

        return mint;
    }
};