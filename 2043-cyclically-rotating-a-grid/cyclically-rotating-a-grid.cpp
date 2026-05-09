class Solution {
public:
    
    void rotateArr(vector<int>& layerEle , int& len, int& k){
        
        vector<int> temp(len);
    
        for(int i=0; i<len; i++){
          temp[i] = layerEle[(i+k)%len];
        }

        layerEle = temp;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k){
        
        int m = grid.size();
        int n = grid[0].size();
        int layer = min(m/2 , n/2);

        for(int l=0; l<layer; l++){
            
            vector<int> layerEle;
            int top = l;
            int bottom = m-l-1;
            int left = l;
            int right = n-l-1;
            
            // top-row L-R
            for(int i=left; i<=right; i++){
               layerEle.push_back(grid[top][i]); 
            }

            //right-col T->D
            for(int i=top+1; i<=bottom-1; i++){
              layerEle.push_back(grid[i][right]); 
            }

            //bottom R->L
            for(int i=right; i>=left; i--){
              layerEle.push_back(grid[bottom][i]); 
            }

            //B->T
            for(int i=bottom-1; i>=top+1; i--){
               layerEle.push_back(grid[i][left]); 
            }

            int len = layerEle.size();
            int rotateK  = k % len;

            rotateArr(layerEle,len,rotateK);
            //rotate(begin(layerEle) , begin(layerEle)+rotateK , end(layerEle));

            int idx = 0;

            // top-row L-R
            for(int i=left; i<=right; i++){
               grid[top][i] = layerEle[idx++];
            }

            //right-col T->D
            for(int i=top+1; i<=bottom-1; i++){
               grid[i][right] = layerEle[idx++];
            }

            //bottom R->L
            for(int i=right; i>=left; i--){
               grid[bottom][i] = layerEle[idx++];
            }

            //B->T
            for(int i=bottom-1; i>=top+1; i--){
               grid[i][left] = layerEle[idx++];
            }

        }
        return grid;
    }
};