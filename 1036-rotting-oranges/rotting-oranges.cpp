class Solution {
public:
     typedef pair<int,int> P;

     vector<vector<int>> dimension = {
        {0,1} , {0, -1} , {1 , 0} , {-1 , 0}
     };

     bool isPossible(int newX , int newY , int m , int n){
        if(newX >= 0 && newX < m && newY >= 0 && newY < n) return true;
        return false;
     }


     /*

     1. decler mint = 0 time and also store all rotate orange coo-dinate in queue for future adcent process
     2. take a size every time with incresing time+1 mint also check the out of box grid adjecnt
     */

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;

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
            bool nonRotate = false;

            for(int i=0; i<size; i++){
                
                P pos = q.front();
                q.pop();

                int x = pos.first;
                int y = pos.second;

                for(auto &it : dimension){

                    int newX = x + it[0];
                    int newY = y + it[1];
                    
                    if(isPossible(newX , newY , m , n) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push({newX , newY});
                        nonRotate = true;
                    }
                }
            }

            if(nonRotate)
             mint++;
        }

        int fresh = 0;

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