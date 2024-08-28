class Solution {
public:

    int m;
    int n;

    void dfs(int i , int j , vector<vector<int>>& grid2 , vector<vector<int>>& st, bool &isOkay){
         
         if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0){
            return;
         }

         if(st[i][j] != 1){
            isOkay = false;
         }

         grid2[i][j] = 0;

         dfs(i   , j+1 , grid2 , st , isOkay);
         dfs(i+1 , j   , grid2 , st , isOkay);
         dfs(i   , j-1 , grid2 , st , isOkay);
         dfs(i-1 , j   , grid2 , st , isOkay);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid2.size();
        n = grid2[0].size();

        int subLand = 0;

        for(int i=0; i<grid2.size(); i++){
          for(int j=0; j<grid2[0].size(); j++){
             
             if(grid2[i][j] == 1){
                bool isOkay = true;
                dfs(i , j , grid2 , grid1 , isOkay);
                if(isOkay){
                    subLand++;
                }
             }
          }
        }
        return subLand;
    }
};