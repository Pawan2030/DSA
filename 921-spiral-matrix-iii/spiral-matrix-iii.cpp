class Solution {
public: 
    
     vector<vector<int>> dir = {
        {0 , 1}, {1 , 0}, {0 , -1}, {-1 , 0}
     };
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> path;
        path.push_back({rStart , cStart});
        int step = 0;
        int d = 0;

        while(path.size() < rows*cols){

            if(d == 0 || d == 2){
                step += 1;
            }

            for(int st = 0; st<step; st++){
                
                rStart += dir[d][0];
                cStart += dir[d][1];
                
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                  path.push_back({rStart , cStart});
            }
            
            d = (d+1)%4;
        }
        return path;
    }
};