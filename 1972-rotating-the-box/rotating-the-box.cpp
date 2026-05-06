class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        

        //lets rotate this into 90*

        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> mat(n , vector<char>(m , '.'));

        for(int i=0; i<m; i++){

            int stone = 0;

            for(int j=0; j<n; j++){

                if(boxGrid[i][j] == '#'){
                    stone++;
                }
                else if(boxGrid[i][j] == '*'){

                    int k = j-1;
                    mat[j][m-i-1] = '*';
                    while(stone>0){
                        mat[k][m-i-1] = '#';
                        k--;
                        stone--;
                    }
                }
            }

            int k = n-1;
            while(stone > 0){
                mat[k][m-i-1] = '#';
                stone--;
                k--;
            }
        }

        return mat;

    }
};