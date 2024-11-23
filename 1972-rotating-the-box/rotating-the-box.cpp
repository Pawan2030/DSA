class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(int c=m-1; c>=0; c--){
            for(int r=0; r<n; r++){
                if(box[r][c] == '#'){
                    //it's stone
                    int col = c;
                    if(col!=m-1){
                        // col++;
                        while(col<m-1 && box[r][col+1] == '.'){
                            col++;
                        }
                        box[r][c] = '.';
                        box[r][col] = '#';
                    }
                }
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++){
        //         cout<<box[i][j]<<" ";
        //     }cout<<endl;
        // }

        //placing the elements in the rotated array
        vector<vector<char>> ans;
        for(int c=0; c<m; c++){
            vector<char> temp;
            for(int r=0; r<n; r++){
                temp.push_back(box[r][c]);
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};