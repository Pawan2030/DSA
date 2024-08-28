class Solution {
public:

    int m;
    int n;

    // void dfs(int i , int j , vector<vector<int>>& grid2 , vector<vector<int>>& st, bool &isOkay){
         
    //      if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0){
    //         return;
    //      }

    //      if(st[i][j] != 1){
    //         isOkay = false;
    //      }

    //      grid2[i][j] = 0;

    //      dfs(i   , j+1 , grid2 , st , isOkay);
    //      dfs(i+1 , j   , grid2 , st , isOkay);
    //      dfs(i   , j-1 , grid2 , st , isOkay);
    //      dfs(i-1 , j   , grid2 , st , isOkay);
    // }

    vector<vector<int>> dirt{{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

    bool bfs(int i , int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2){

        queue<pair<int,int>> q;
        q.push({i , j});
        grid2[i][j] = -1;

        bool res = true;

        while(!q.empty()){

            auto top = q.front();
            q.pop();

            int x = top.first;
            int y = top.second;

            if(grid1[x][y] != 1){
                res = false;
            }

            for(auto it : dirt){

                int new_x = x+it[0];
                int new_y = y+it[1];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid2[new_x][new_y] == 1){
                    grid2[new_x][new_y] = -1;
                    q.push({new_x , new_y});
                }
            }
        }
        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid2.size();
        n = grid2[0].size();

        int subLand = 0;

        for(int i=0; i<grid2.size(); i++){
          for(int j=0; j<grid2[0].size(); j++){
             
             if(grid2[i][j] == 1){
                if(bfs(i , j , grid1 , grid2)){
                    subLand++;
                }
             }
          }
        }
        return subLand;
    }
};