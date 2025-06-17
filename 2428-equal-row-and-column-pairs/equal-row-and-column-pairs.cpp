class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        unordered_map<int , vector<int>> row;

        int i = 0;

        while(i < m){

            for(int j=0; j<n; j++){
                row[i].push_back(grid[i][j]);
            }
            i++;
        }

        unordered_map<int , vector<int>> col;
        int j = 0;

        while(j < n){

            for(int i=0; i<m; i++){
                col[j].push_back(grid[i][j]);
            }

            //check logic

            vector<int> vec1 = col[j];

            for(auto it : row){

               vector<int> vec2 = it.second; 

               if(vec1 == vec2){
                  count++;
               }
            }

            j++;
        }
        return count;
    }
};