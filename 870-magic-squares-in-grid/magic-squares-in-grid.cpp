class Solution {
public:

    void isDistinct(int x , int y , vector<vector<int>>& grid , bool &okay){
        
        unordered_set<int> st;

        for(int i=0; i<3; i++){

            for(int j=0; j<3; j++){

             if(grid[x+i][y+j] <=0 || grid[x+i][y+j] > 9 || st.count(grid[x+i][y+j])){
               okay = false;
               break;
              }
             st.insert(grid[x+i][y+j]);
           }
        }
    }

    void isrowcoldagsum(int x , int y , vector<vector<int>>& grid , bool &okay){
        int equal = grid[x][y] + grid[x][y+1] + grid[x][y+2];

        for(int i=0; i<3; i++){

            if(equal != grid[x+i][y] + grid[x+i][y+1] + grid[x+i][y+2]){
                okay = false;
                break;
            }

            if(equal != grid[x][y+i] + grid[x+1][y+i] + grid[x+2][y+i]){
                okay = false;
                break;
            }
        }

        if(equal != grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2]){
            okay = false;
        }

        if(equal != grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y]){
            okay = false;
        }
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        if(row < 3 || col < 3) return 0;

        for(int i=0; i<=row-3; i++){
            for(int j=0; j<=col-3; j++){

                bool okay = true;

                isDistinct(i , j , grid , okay);
                isrowcoldagsum(i , j , grid , okay);
                
                if(okay){
                    count++;
                }
            }
        }
        return count;
    }
};