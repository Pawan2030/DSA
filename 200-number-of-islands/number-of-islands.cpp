class Solution {
public:
    
    int m;
    int n;

    vector<vector<int>> dir = {
        {0,1},{1,0},{0,-1},{-1,0}
    };

    void dfs(int x , int y , vector<vector<char>>& grid , vector<vector<bool>>& visited){
         
         visited[x][y] = true;

         for(auto it : dir){
             
             int i = x + it[0];
             int j = y + it[1];

             if(i>=0 && i<m && j>=0 && j<n && visited[i][j] == false && grid[i][j] == '1'){
                dfs(i , j , grid , visited);
             }
         }
    }

    int numIslands(vector<vector<char>>& grid) {
       
       m = grid.size();
       n = grid[0].size();
       int island = 0;

       vector<vector<bool>> visited(m , vector<bool>(n , false));

       for(int i=0; i<m; i++){
          
          for(int j=0; j<n; j++){
              
              if(grid[i][j] == '1' && visited[i][j] == false){
                 island++;
                 //cout<<"hi"<<endl;
                 dfs(i , j , grid , visited);
              }
          }
       }
       return island;
    }
};