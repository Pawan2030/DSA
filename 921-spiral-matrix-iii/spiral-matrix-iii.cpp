class Solution {
public:

    vector<vector<int>> dir = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
         
         int n = rows*cols;
         vector<vector<int>> path;

         path.push_back({rStart , cStart});

         int i = rStart;
         int j = cStart;

         int step = 0;

        while(path.size() < n){
          
          //east
          step += 1;
          int k = step;

          while(k--){
             
             i += dir[0][0];
             j += dir[0][1];

             if(i >=0 && i < rows && j >= 0 && j < cols){
                path.push_back({i , j});
             }
          }

          //south
            k = step;
            while(k--){
             
            i += dir[1][0];
            j += dir[1][1];

            if(i >=0 && i < rows && j >= 0 && j < cols){
                path.push_back({i , j});
            }
          }

          //west
          step += 1;
          k = step;

            while(k--){
             
            i += dir[2][0];
            j += dir[2][1];

            if(i >=0 && i < rows && j >= 0 && j < cols){
                path.push_back({i , j});
            }
          }

          //north

            k = step;

            while(k--){
             
            i += dir[3][0];
            j += dir[3][1];

            if(i >=0 && i < rows && j >= 0 && j < cols){
                path.push_back({i , j});
            }
          }

        }

        return path;

    }
};